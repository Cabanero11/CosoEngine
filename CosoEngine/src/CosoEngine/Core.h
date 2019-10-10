#pragma once

#ifdef COSO_PLATFORM_WINDOWS
	#ifdef COSO_BUILD_DLL
		#define COSOENGINE_API __declspec(dllexport)
	#else
		#define COSOENGINE_API __declspec(dllimport)
	#endif
#else
	#error Coso Engine only Supports Windows!
#endif

#define BIT(x) (1 << x)
