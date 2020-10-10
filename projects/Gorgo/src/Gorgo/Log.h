#pragma once
#include <memory>
#include <spdlog/spdlog.h>
#include "Core.h"

namespace Gorgo 
{
	/// <summary>
	/// Class that wraps library spdlog in order to generate logs. There are 2 loggers available,
	/// core and client loggers which both can show different types of logs such warnings, trace, error...
	/// </summary>
	class GRG_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() {
			return _CORE_LOGGER;
		}

		inline static std::shared_ptr<spdlog::logger> GetClientLogger() {
			return _CLIENT_LOGGER;
		}

	private:
		static std::shared_ptr<spdlog::logger> _CORE_LOGGER;
		static std::shared_ptr<spdlog::logger> _CLIENT_LOGGER;

	};
}

//Core log macros. Ordered from mild to important
#define GRG_CORE_TRACE(...)		::Gorgo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GRG_CORE_INFO(...)		::Gorgo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GRG_CORE_WARN(...)		::Gorgo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GRG_CORE_ERROR(...)		::Gorgo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GRG_CORE_FATAL(...)		::Gorgo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Application log macros. Ordered from mild to important
#define GRG_TRACE(...)		::Gorgo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GRG_INFO(...)		::Gorgo::Log::GetClientLogger()->info(__VA_ARGS__)
#define GRG_WARN(...)		::Gorgo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GRG_ERROR(...)		::Gorgo::Log::GetClientLogger()->error(__VA_ARGS__)
#define GRG_FATAL(...)		::Gorgo::Log::GetClientLogger()->fatal(__VA_ARGS__)