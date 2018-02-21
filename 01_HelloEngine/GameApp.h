#ifndef INCLUDED_GAMEAPP_H
#define INCLUDED_GAMEAPP_H

#include <Core\Inc\Core.h>
#include <Graphics\Inc\Graphics.h>

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
};

#endif // !INCLUDED_GAMEAPP_H
