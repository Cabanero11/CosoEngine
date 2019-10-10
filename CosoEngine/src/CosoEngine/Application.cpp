#include "Application.h"

#include "CosoEngine/Events/ApplicationEvent.h"
#include "CosoEngine/Log.h"

namespace CosoEngine {
	

	Application::Application()
	{

	}


	Application::~Application()
	{

	}



	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);

		if(e.IsInCategory(EventCategoryApplication)) 
		{
			COSO_TRACE(e);
		}
		if(e.IsInCategory(EventCategoryInput))
		{
			COSO_TRACE(e);
		}



		while (true);
	}
}