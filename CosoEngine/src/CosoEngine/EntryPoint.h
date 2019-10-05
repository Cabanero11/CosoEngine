#pragma once


#ifdef COSO_PLATFORM_WINDOWS

extern CosoEngine::Application* CosoEngine::CreateApplication();

int main(int argc, char** argv)		
{
	auto app = CosoEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif
