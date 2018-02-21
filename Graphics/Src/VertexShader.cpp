#include "Precompiled.h"
#include "VertexShader.h"
#include "GraphicsSystem.h"
#include "VertexTypes.h"

namespace CCGE {
namespace Graphics {

namespace
{
	std::vector<D3D11_INPUT_ELEMENT_DESC> GetVertexDescription(int/*uint32_t*/ vertexFormat)
	{
		std::vector<D3D11_INPUT_ELEMENT_DESC> desc;

		if (vertexFormat & VF_POSITION)
		{
			desc.push_back({
				"POSITION", 0,
				DXGI_FORMAT_R32G32B32_FLOAT, 0,
				D3D11_APPEND_ALIGNED_ELEMENT,
				D3D11_INPUT_PER_VERTEX_DATA, 0
			});
		}
		if (vertexFormat & VF_NORMAL)
		{
			desc.push_back({
				"NORMAL", 0,
				DXGI_FORMAT_R32G32B32_FLOAT, 0,
				D3D11_APPEND_ALIGNED_ELEMENT,
				D3D11_INPUT_PER_VERTEX_DATA, 0
			});
		}
		if (vertexFormat & VF_TANGENT)
		{
			desc.push_back({
				"TANGENT", 0,
				DXGI_FORMAT_R32G32B32_FLOAT, 0,
				D3D11_APPEND_ALIGNED_ELEMENT,
				D3D11_INPUT_PER_VERTEX_DATA, 0
			});
		}
		if (vertexFormat & VF_COLOR)
		{
			desc.push_back({
				"COLOR", 0,
				DXGI_FORMAT_R32G32B32A32_FLOAT, 0,
				D3D11_APPEND_ALIGNED_ELEMENT,
				D3D11_INPUT_PER_VERTEX_DATA, 0
			});
		}
		if (vertexFormat & VF_UV)
		{
			desc.push_back({
				"TEXCOORD", 0,
				DXGI_FORMAT_R32G32_FLOAT, 0,
				D3D11_APPEND_ALIGNED_ELEMENT,
				D3D11_INPUT_PER_VERTEX_DATA, 0
			});
		}
		if (vertexFormat & VF_BINDEX)
		{
			desc.push_back({
				"BLENDINDEX", 0,
				DXGI_FORMAT_R32G32B32A32_SINT, 0,
				D3D11_APPEND_ALIGNED_ELEMENT,
				D3D11_INPUT_PER_VERTEX_DATA, 0
			});
		}
		if (vertexFormat & VF_BWEIGHT)
		{
			desc.push_back({"BLENDWEIGHT", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0});
		}

		return desc;
	}
}

const D3D11_INPUT_ELEMENT_DESC kVertexLayout[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

VertexShader::VertexShader()
	: mInputLayout(nullptr)
	, mVertexShader(nullptr)
{
}

VertexShader::~VertexShader()
{
	Terminate();
}

void VertexShader::Initialize(ID3DBlob* shaderBlob, ID3DBlob* errorBlob, LPCWSTR fileName, int/*uint32_t*/ vertexFormat)
{
	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	const auto vertexDesc = GetVertexDescription(vertexFormat);

	GraphicsSystem::Get()->GetDevice()->CreateVertexShader
	(
		shaderBlob->GetBufferPointer(),
		shaderBlob->GetBufferSize(),
		nullptr,
		&mVertexShader
	);

	GraphicsSystem::Get()->GetDevice()->CreateInputLayout
	(
		vertexDesc.data(),
		(UINT)vertexDesc.size(),
		shaderBlob->GetBufferPointer(),
		shaderBlob->GetBufferSize(),
		&mInputLayout
	);
	SafeRelease(shaderBlob);
}

void VertexShader::Terminate()
{
	SafeRelease(mVertexShader);
	SafeRelease(mInputLayout);
}

void VertexShader::Bind()
{
	ID3D11DeviceContext* context = Graphics::GraphicsSystem::Get()->GetContext();
	context->IASetInputLayout(mInputLayout);
	context->VSSetShader(mVertexShader, nullptr, 0);
}

}
}