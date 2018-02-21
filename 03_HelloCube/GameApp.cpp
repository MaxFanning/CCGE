#include "GameApp.h"

using namespace CCGE;

namespace // Internal Linkage
{
	const Graphics::VertexPC kVertices[] =
	{
		{ CMath::Vector3(-0.5f,  0.5f,  0.5f), CMath::Vector4::Blue() },
		{ CMath::Vector3( 0.5f,  0.5f,  0.5f), CMath::Vector4::Green() },
		{ CMath::Vector3( 0.5f, -0.5f,  0.5f), CMath::Vector4::Green() },
		{ CMath::Vector3(-0.5f, -0.5f,  0.5f), CMath::Vector4::Blue() },
									    
		{ CMath::Vector3(-0.5f,  0.5f, -0.5f), CMath::Vector4::Blue() },
		{ CMath::Vector3( 0.5f,  0.5f, -0.5f), CMath::Vector4::Green() },
		{ CMath::Vector3( 0.5f, -0.5f, -0.5f), CMath::Vector4::Green() },
		{ CMath::Vector3(-0.5f, -0.5f, -0.5f), CMath::Vector4::Blue() },
	};

	const int kVertexCount = sizeof(kVertices) / sizeof(kVertices[0]);

	const int kIndices[] =
	{
		// face
		0, 1, 2,
		0, 2, 3,

		// left
		4, 0, 3,
		4, 3, 7,

		// right
		1, 5, 6,
		1, 6, 2,

		// up
		4, 5, 1,
		4, 1, 0,

		// down
		3, 2, 6,
		3, 6, 7,

		// back
		5, 4, 7,
		5, 7, 6
	};
	const int kIndexCount = sizeof(kIndices) / sizeof(kIndices[0]);
}

GameApp::GameApp()
	: mConstantBuffer(nullptr)
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
	auto device = graphicsSystem->GetDevice();
	
	mMeshBuffer.Initialize(kVertices, sizeof(kVertices[0]), kVertexCount, kIndices, kIndexCount);

	// Create and fill constant buffer
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.ByteWidth = sizeof(CMath::Matrix) * 3;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	device->CreateBuffer(&bufferDesc, nullptr, &mConstantBuffer);

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

	mVertexShader.Initialize(shaderBlob, errorBlob, L"../Assets/Shaders/DoTransform.fx", Graphics::VertexPC::Format);
	mPixelShader.Initialize(shaderBlob, errorBlob, L"../Assets/Shaders/DoTransform.fx");
}

void GameApp::OnTerminate()
{
	SafeRelease(mConstantBuffer);

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

	static float rotationX = 0.0f;
	static float rotationY = 0.0f;
	if (GetAsyncKeyState(VK_LEFT))
	{
		rotationY += 0.05f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		rotationY -= 0.05f;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		rotationX += 0.05f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		rotationX -= 0.05f;
	}

	auto graphicsSystem = Graphics::GraphicsSystem::Get();
	graphicsSystem->BeginRender();

	ID3D11DeviceContext* context = graphicsSystem->GetContext();
	mVertexShader.Bind();
	mPixelShader.Bind();

	CMath::Matrix world, view, projection;
	world = CMath::Matrix::RotationX(rotationX) * CMath::Matrix::RotationY(rotationY);
	view = CMath::Matrix
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 3.0f, 1.0f
	);
	projection = CMath::Matrix
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, -1.0f, 0.0f
	);

	// Update matrices
	CMath::Matrix matrices[3];
	matrices[0] = CMath::Transpose(world);
	matrices[1] = CMath::Transpose(view);
	matrices[2] = CMath::Transpose(projection);
	context->UpdateSubresource(mConstantBuffer, 0, nullptr, matrices, 0, 0);
	context->VSSetConstantBuffers(0, 1, &mConstantBuffer);

	mMeshBuffer.Render();
	graphicsSystem->EndRender();
}
