#include "GameApp.h"

using namespace CCGE;

namespace // Internal Linkage
{
	const SimpleVertex kTriForceVertices[] =
	{
		{ CMath::Vector3( 0.0f,  0.5f, 0.0f), CMath::Vector4::Red() },
		{ CMath::Vector3( 0.25f,  0.0f, 0.0f), CMath::Vector4::Green() },
		{ CMath::Vector3( -0.25f, 0.0f, 0.0f), CMath::Vector4::Blue() },

		{ CMath::Vector3( 0.25f,  0.0f, 0.0f), CMath::Vector4::Red() },
		{ CMath::Vector3( 0.5f,  -0.5f, 0.0f), CMath::Vector4::Green() },
		{ CMath::Vector3( 0.0f,  -0.5f, 0.0f), CMath::Vector4::Blue() },

		{ CMath::Vector3(-0.25f,  0.0f, 0.0f), CMath::Vector4::Red() },
		{ CMath::Vector3(0.0f,  -0.5f, 0.0f), CMath::Vector4::Green() },
		{ CMath::Vector3(-0.5f, -0.5f, 0.0f), CMath::Vector4::Blue() },
	};

	const SimpleVertex kHeartVertices[] =
	{
		{ CMath::Vector3(-0.25f,  0.25f, 0.0f), CMath::Vector4::Red() },
		{ CMath::Vector3(0.25f, 0.25f, 0.0f), CMath::Vector4::Green() },
		{ CMath::Vector3(0.0f,  -0.75f, 0.0f), CMath::Vector4::Blue() },

		{ CMath::Vector3(-0.25f,  0.25f, 0.0f), CMath::Vector4::Red() },
		{ CMath::Vector3(-0.13f, 0.5f, 0.0f), CMath::Vector4::Green() },
		{ CMath::Vector3(0.0f,  0.25f, 0.0f), CMath::Vector4::Blue() },

		{ CMath::Vector3(0.0f,  0.25f, 0.0f), CMath::Vector4::Red() },
		{ CMath::Vector3(0.13f, 0.5f, 0.0f), CMath::Vector4::Green() },
		{ CMath::Vector3(0.25f,  0.25f, 0.0f), CMath::Vector4::Blue() },
	};

	const int kTriForceVertexCount = sizeof(kTriForceVertices) / sizeof(kTriForceVertices[0]);
	const int kHeartVertexCount = sizeof(kHeartVertices) / sizeof(kHeartVertices[0]);
}

GameApp::GameApp()
	: mTriForceVertexBuffer(nullptr)
	, mHeartVertexBuffer(nullptr)
	, mCurrentBuffer(nullptr)
	, mCurrentCount(0)
{
}

GameApp::~GameApp()
{
}


void GameApp::OnInitialize()
{
	mWindow.Initialize(GetInstance(), GetAppName(), 1280, 720);
	Graphics::GraphicsSystem::StaticInitialize(mWindow.GetWindowHandle(), false);

	auto graphicsSystem = Graphics::GraphicsSystem::Get();

	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(SimpleVertex) * kTriForceVertexCount;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = kTriForceVertices;

	// TriForce
	graphicsSystem->GetDevice()->CreateBuffer(&bufferDesc, &initData, &mTriForceVertexBuffer);
	mCurrentBuffer = mTriForceVertexBuffer;
	mCurrentCount = kTriForceVertexCount;

	// Triangle
	initData.pSysMem = kHeartVertices;
	bufferDesc.ByteWidth = sizeof(SimpleVertex) * kHeartVertexCount;
	graphicsSystem->GetDevice()->CreateBuffer(&bufferDesc, &initData, &mHeartVertexBuffer);

	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	ID3DBlob* shaderBlob = nullptr;
	ID3DBlob* errorBlob = nullptr;
	HRESULT hr = D3DCompileFromFile
	(
		L"../Assets/Shaders/DoTransform.fx",
		nullptr,
		nullptr,
		"VS",
		"vs_5_0",
		shaderFlags,
		0,
		&shaderBlob,
		&errorBlob
	);
	ASSERT(SUCCEEDED(hr), "Failed to compile shader. Error: %s", (const char*)errorBlob->GetBufferPointer());
	SafeRelease(errorBlob);

	mVertexShader.Initialize(shaderBlob, errorBlob, L"../Assets/Shaders/DoNothing.fx", Graphics::VertexPC::Format);
	mPixelShader.Initialize(shaderBlob, errorBlob, L"../Assets/Shaders/DoNothing.fx");
}

void GameApp::OnTerminate()
{
	SafeRelease(mTriForceVertexBuffer);
	SafeRelease(mHeartVertexBuffer);
	SafeRelease(mCurrentBuffer);

	Graphics::GraphicsSystem::StaticTerminate();
	mWindow.Terminate();
}

void GameApp::OnUpdate()
{
	if (mWindow.ProcessMessage())
	{
		Kill();
		return;
	}

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
		return;
	}

	if (GetAsyncKeyState(VK_F1))
	{
		mCurrentBuffer = mTriForceVertexBuffer;
		mCurrentCount = kTriForceVertexCount;
	}
	else if (GetAsyncKeyState(VK_F2))
	{
		mCurrentBuffer = mHeartVertexBuffer;
		mCurrentCount = kHeartVertexCount;
	}

	auto graphicsSystem = Graphics::GraphicsSystem::Get();
	graphicsSystem->BeginRender();

	ID3D11DeviceContext* context = graphicsSystem->GetContext();
	mVertexShader.Bind();
	mPixelShader.Bind();

	UINT stride = sizeof(SimpleVertex);
	UINT offset = 0;
	
	context->IASetVertexBuffers(0, 1, &mCurrentBuffer, &stride, &offset);

	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	context->Draw(mCurrentCount, 0);

	graphicsSystem->EndRender();
}
