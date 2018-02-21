#ifndef INCLUDED_GRAPHICS_VERTEXTYPES_H
#define INCLUDED_GRAPHICS_VERTEXTYPES_H

#define VF_POSITION 0x1 << 0
#define VF_NORMAL   0x1 << 1
#define VF_TANGENT  0x1 << 2
#define VF_COLOR    0x1 << 3
#define VF_UV       0x1 << 4
#define VF_BINDEX   0x1 << 5
#define VF_BWEIGHT  0x1 << 6

namespace CCGE {
namespace Graphics {

struct VertexP
{
	static const /*uint32_t*/int Format = VF_POSITION;
	CMath::Vector3 position;
};

struct VertexPC
{
	static const int Format = VF_POSITION | VF_COLOR;
	CMath::Vector3 position;
	CMath::Vector4 color;
};

struct VertexPt
{
	static const int Format = VF_POSITION | VF_UV;
	CMath::Vector3 position;
	CMath::Vector2 uv;
};

struct Vertex
{
	static const int Format = VF_POSITION | VF_NORMAL | VF_TANGENT | VF_COLOR | VF_UV;
	CMath::Vector3 position;
	CMath::Vector3 normal;
	CMath::Vector3 tangent;
	CMath::Vector4 color;
	CMath::Vector2 uv;
};

}
}

#endif // !INCLUDED_GRAPHICS_VERTEXTYPES_H
