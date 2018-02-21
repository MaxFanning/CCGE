#ifndef INCLUDED_GAMEAPP_H
#define INCLUDED_GAMEAPP_H

#include <Core\Inc\Core.h>
#include <Graphics\Inc\Graphics.h>
#include <Graphics\Inc\VertexShader.h>
#include <Graphics\Inc\PixelShader.h>

//class SimpleVertex;
struct SimpleVertex
{
	CCGE::CMath::Vector3 position;
	CCGE::CMath::Vector4 color;
};

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

	ID3D11Buffer* mTriForceVertexBuffer;
	ID3D11Buffer* mHeartVertexBuffer;

	CCGE::Graphics::VertexShader mVertexShader;
	CCGE::Graphics::PixelShader mPixelShader;

	ID3D11Buffer* mCurrentBuffer;
	int mCurrentCount;
};

#endif // !INCLUDED_GAMEAPP_H
