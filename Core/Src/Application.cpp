#include "Precompiled.h"
#include "Application.h"

using namespace CCGE;
using namespace CCGE::Core;

Application::Application()
	: mInstance(nullptr)
	, mRunning(true)
{
}

Application::~Application()
{
}

void Application::Initialize(HINSTANCE instance, LPCSTR appName)
{
	mInstance = instance;
	mAppName = appName;

	CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	OnInitialize();
}

void Application::Terminate()
{
	OnTerminate();

	CoUninitialize();
}

void Application::Update()
{
	OnUpdate();
}