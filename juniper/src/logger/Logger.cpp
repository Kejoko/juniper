//==========================================================================================
// Logger.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages using spdlog
//==========================================================================================

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <Core.h>

#include <spdlog/async.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Logger.h"

namespace Juniper {

    std::shared_ptr<spdlog::async_logger> Logger::juniper_logger;

    void Logger::init(std::string title) {
        
        std::vector<spdlog::sink_ptr> sinks;
        sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(title + "-log.txt", true));
        sinks[0]->set_pattern("[%D %T.%f%z] [%l]\t[%s|%!|%#] %v");
        
        #ifdef DEBUG
        sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        sinks[1]->set_pattern("[%T.%F] [%^%s | %! | %#%$] %v");
        #endif // DEBUG
        
        spdlog::init_thread_pool(10000, 1);
        juniper_logger = std::make_shared<spdlog::async_logger>("Juniper", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::overrun_oldest);
        juniper_logger->set_level(spdlog::level::trace);
        juniper_logger->flush_on(spdlog::level::trace);
        sinks[0]->set_level(spdlog::level::info);
        
        spdlog::register_logger(juniper_logger);
        spdlog::set_default_logger(juniper_logger);
    }

    void Logger::cleanup() {
        spdlog::shutdown();
    }

}
