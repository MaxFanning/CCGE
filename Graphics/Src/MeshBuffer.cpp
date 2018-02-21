#include "Precompiled.h"
#include "MeshBuffer.h"
#include "VertexShader.h"
#include "GraphicsSystem.h"
#include "03_HelloCube\GameApp.h"

namespace CCGE {
namespace Graphics {

MeshBuffer::MeshBuffer()
	: mVertexBuffer(nullptr)
	, mIndexBuffer(nullptr)
	, mIndexCount(0)
	, mVertexCount(0)
{
}

MeshBuffer::~MeshBuffer()
{
	ASSERT(mVertexBuffer == nullptr, "[MeshBuffer] Vertex buffer not released!");
	ASSERT(mIndexBuffer == nullptr, "[MeshBuffer] Index buffer not released!");
	Terminate();
}

void MeshBuffer::Initialize(const Mesh& mesh)
{
	Initialize(mesh.GetVertices(), sizeof(Vertex), mesh.GetVertexCount(), mesh.GetIndices(), mesh.GetIndexCount());
}

void MeshBuffer::Initialize(const void* vertices, const unsigned long long vertexSize, const int vertexCount, const int* indices, const int indexCount)
{
	mVertexCount = vertexCount;
	mIndexCount = indexCount;

	// Create Vertex Buffer
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = vertexSize * mVertexCount;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = vertices;

	GraphicsSystem::Get()->GetDevice()->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer);

	//--------------------------------------------------------------------------------------------------
	// Create and fill index buffer
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(int) * mIndexCount;
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	initData.pSysMem = indices;

	GraphicsSystem::Get()->GetDevice()->CreateBuffer(&bufferDesc, &initData, &mIndexBuffer);

}

void MeshBuffer::Initialize(const void* vertices, const unsigned long long vertexSize, const int vertexCount)
{
	mVertexCount = vertexCount;

	// Create Vertex Buffer
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = vertexSize * mVertexCount;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = vertices;

	GraphicsSystem::Get()->GetDevice()->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer);
}

void MeshBuffer::Terminate()
{
	SafeRelease(mVertexBuffer);
	SafeRelease(mIndexBuffer);
}

void MeshBuffer::Render()
{
	// Set vertex buffer
	UINT stride = sizeof(Graphics::VertexPC); // TODO: FIX!
	UINT offset = 0;
	auto context = GraphicsSystem::Get()->GetContext();
	context->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);

	// Set primitive topology
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// If using index buffer
	if (mIndexBuffer != nullptr)
	{
		// Set index buffer
		context->IASetIndexBuffer(mIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

		// Draw indexed mesh
		context->DrawIndexed(mIndexCount, 0, 0);
	}
	else
	{
		// Draw mesh
		context->Draw(mVertexCount, 0);
	}
}

}
}