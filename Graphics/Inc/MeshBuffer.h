#ifndef INCLUDED_MESHBUFFER_HEADER_H
#define INCLUDED_MESHBUFFER_HEADER_H
#include "Common.h"

namespace CCGE {
namespace Graphics {

class Mesh;

class MeshBuffer
{
public:
	MeshBuffer();
	~MeshBuffer();

	void Initialize(const Mesh&);
	void Initialize(const void* vertices, const unsigned long long vertexSize, const int vertexCount, const int* indices, const int indexCount);
	void Initialize(const void* vertices, const unsigned long long vertexSize, const int vertexCount);

	void Terminate();

	void Render();

private:
	MeshBuffer(const MeshBuffer&) = delete;
	MeshBuffer& operator=(const MeshBuffer&) = delete;

	ID3D11Buffer* mVertexBuffer;
	ID3D11Buffer* mIndexBuffer;

	int mVertexCount;
	int mIndexCount;

};

}
}

#endif // !INCLUDED_MESHBUFFER_HEADER_H
