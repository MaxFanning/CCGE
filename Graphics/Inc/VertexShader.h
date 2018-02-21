#ifndef INCLUDED_VERTEX_SHADER_HEADER_H
#define INCLUDED_VERTEX_SHADER_HEADER_H
#include "Common.h"

namespace CCGE {
namespace Graphics {

class VertexShader
{
public:
	VertexShader();
	~VertexShader();

	void Initialize(ID3DBlob* shaderBlob, ID3DBlob* errorBlob, LPCWSTR fileName, int/*uint32_t*/ vertexFormat);
	void Terminate();

	void Bind();

private:
	ID3D11InputLayout* mInputLayout;
	ID3D11VertexShader* mVertexShader;

};

} // Graphics Namespace
} // CCGE Namespace

#endif // !INCLUDED_VERTEX_SHADER_HEADER_H
