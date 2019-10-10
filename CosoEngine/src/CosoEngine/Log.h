#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"


namespace CosoEngine {

	class COSOENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log macros
#define COSO_CORE_TRACE(...)    ::CosoEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define COSO_CORE_INFO(...)     ::CosoEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define COSO_CORE_WARN(...)     ::CosoEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define COSO_CORE_ERROR(...)    ::CosoEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define COSO_CORE_FATAL(...)    ::CosoEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define COSO_TRACE(...)         ::CosoEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define COSO_INFO(...)          ::CosoEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define COSO_WARN(...)          ::CosoEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define COSO_ERROR(...)         ::CosoEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define COSO_FATAL(...)         ::CosoEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

