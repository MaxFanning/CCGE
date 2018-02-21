#include "Precompiled.h"
#include "Mesh.h"

using namespace CCGE;
using namespace CCGE::Graphics;

Mesh::Mesh()
	: mVertices(nullptr)
	, mIndices(nullptr)
	, mNumVertices(0)
	, mNumIndices(0)
{
}

Mesh::~Mesh()
{
	ASSERT(mVertices == nullptr, "[Mesh] Vertices not released!");
	ASSERT(mIndices == nullptr, "[Mesh] Indices not released!");
}

void Mesh::Allocate(uint32_t numVertices, uint32_t numIndices)
{
	ASSERT(numVertices > 0, "[Mesh] Invalid count.");
	ASSERT(numIndices > 0, "[Mesh] Invalid count.");

	Destroy();

	mNumVertices = numVertices;
	mNumIndices = numIndices;

	mVertices = new Vertex[mNumVertices];
	mIndices = new uint32_t[mNumIndices];
}

void Mesh::Destroy()
{
	SafeRelease(mVertices);
	SafeRelease(mIndices);
	mNumVertices = 0;
	mNumIndices = 0;
}

Vertex& Mesh::GetVertex(uint32_t index)
{
	ASSERT(index < mNumVertices, "[Mesh] Invalid index.");
	return mVertices[index];
}

uint32_t& Mesh::GetIndex(uint32_t index)
{
	ASSERT(index < mNumIndices, "[Mesh] Invalid index.");
	return mIndices[index];
}