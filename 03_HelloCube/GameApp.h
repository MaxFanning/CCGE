#ifndef INCLUDED_GAMEAPP_H
#define INCLUDED_GAMEAPP_H

#include <Core\Inc\Core.h>
#include <Graphics\Inc\Graphics.h>
#include <Graphics\Inc\VertexShader.h>
#include <Graphics\Inc\PixelShader.h>
#include <Graphics\Inc\MeshBuffer.h>

class GameApp : public CCGE::Core::Application
{
public:
	GameApp();
	~GameApp() override;

private:
	void OnInitialize() override;
	void OnTerminate() override;
	void OnUpdate() override;

	CCGE::Core::Window mWindow;

	ID3D11Buffer* mConstantBuffer;

	CCGE::Graphics::MeshBuffer mMeshBuffer;
	CCGE::Graphics::VertexShader mVertexShader;
	CCGE::Graphics::PixelShader mPixelShader;
};

#endif // !INCLUDED_GAMEAPP_H
