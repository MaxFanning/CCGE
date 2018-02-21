#include "Precompiled.h"
#include "PixelShader.h"
#include "GraphicsSystem.h"

namespace CCGE {
namespace Graphics {

PixelShader::PixelShader()
	: mPixelShader(nullptr)
{
}

PixelShader::~PixelShader()
{
	Terminate();
}

void PixelShader::Initialize(ID3DBlob* shaderBlob, ID3DBlob* errorBlob, LPCWSTR fileName)
{
	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	HRESULT hr = D3DCompileFromFile
	(
		fileName,
		nullptr,
		nullptr,
		"PS",
		"ps_5_0",
		shaderFlags,
		0,
		&shaderBlob,
		&errorBlob
	);
	ASSERT(SUCCEEDED(hr), "Failed to compile shader. Error: %s", (const char*)errorBlob->GetBufferPointer());
	SafeRelease(errorBlob);

	GraphicsSystem::Get()->GetDevice()->CreatePixelShader
	(
		shaderBlob->GetBufferPointer(),
		shaderBlob->GetBufferSize(),
		nullptr,
		&mPixelShader
	);
	SafeRelease(shaderBlob);
}

void PixelShader::Terminate()
{
	SafeRelease(mPixelShader);
}

void PixelShader::Bind()
{
	Graphics::GraphicsSystem::Get()->GetContext()->PSSetShader(mPixelShader, nullptr, 0);
}

}
}