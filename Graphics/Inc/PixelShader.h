#ifndef INCLUDED_PIXEL_SHADER_HEADER_H
#define INCLUDED_PIXEL_SHADER_HEADER_H
#include "Common.h"

namespace CCGE {
namespace Graphics {

class PixelShader
{
public:
	PixelShader();
	~PixelShader();

	void Initialize(ID3DBlob* shaderBlob, ID3DBlob* errorBlob, LPCWSTR fileName);
	void Terminate();

	void Bind();

private:
	ID3D11PixelShader* mPixelShader;

};

} // Graphics Namespace
} // CCGE Namespace

#endif // !INCLUDED_VERTEX_SHADER_HEADER_H
