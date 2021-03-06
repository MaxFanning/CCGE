#ifndef INCLUDED_GRAPHICS_MESH_H
#define INCLUDED_GRAPHICS_MESH_H

#include "VertexTypes.h"

namespace CCGE {
namespace Graphics {

class Mesh
{
public:
	Mesh();
	~Mesh();

	void Allocate(uint32_t numVertices, uint32_t numIndices);
	void Destroy();

	Vertex&   GetVertex (uint32_t index);
	uint32_t& GetIndex  (uint32_t index);

	const Vertex* GetVertices() const  { return mVertices; }
	const uint32_t* GetIndices() const { return mIndices; }
	uint32_t GetVertexCount() const    { return mNumVertices; }
	uint32_t GetIndexCount() const     { return mNumIndices; }

private:
	Mesh(const Mesh&) = delete;
	Mesh& operator=(const Mesh&) = delete;

	Vertex* mVertices;
	uint32_t* mIndices;

	uint32_t mNumVertices;
	uint32_t mNumIndices;

};

}
}

#endif // #ifndef INCLUDED_GRAPHICS_MESH_H
