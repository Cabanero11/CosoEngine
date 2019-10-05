#include <CosoEngine.h>

class SandBox : public CosoEngine::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}

};


CosoEngine::Application* CosoEngine::CreateApplication()
{
	return new SandBox();
}