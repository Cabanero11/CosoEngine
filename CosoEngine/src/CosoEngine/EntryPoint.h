#pragma once


#ifdef COSO_PLATFORM_WINDOWS

extern CosoEngine::Application* CosoEngine::CreateApplication();

int main(int argc, char** argv)		
{
	CosoEngine::Log::Init();
	COSO_CORE_WARN("Inicialited Log");
	int a = 5;
	COSO_INFO("Hello Var={0}", a);


	auto app = CosoEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif
