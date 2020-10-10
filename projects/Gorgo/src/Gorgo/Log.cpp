#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Gorgo {

	std::shared_ptr<spdlog::logger> Log::_CORE_LOGGER;
	std::shared_ptr<spdlog::logger> Log::_CLIENT_LOGGER;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_CORE_LOGGER = spdlog::stdout_color_mt("GORGO");
		_CORE_LOGGER->set_level(spdlog::level::trace);

		_CLIENT_LOGGER = spdlog::stdout_color_mt("APP");
		_CLIENT_LOGGER->set_level(spdlog::level::trace);
	}
}

