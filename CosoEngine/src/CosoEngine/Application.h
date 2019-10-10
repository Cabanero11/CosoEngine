#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace CosoEngine {
	
	class COSOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// You have to define it in the client
	Application* CreateApplication();
}

