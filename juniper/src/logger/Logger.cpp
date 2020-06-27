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

std::shared_ptr<spdlog::async_logger> Logger::juniper_logger;

void Logger::init(std::string title) {
    
    std::vector<spdlog::sink_ptr> sinks;
    sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(title + "-log.txt", true));
    
    sinks[0]->set_pattern("[%T.%F] [%^%s | %! | %#%$] %v");
    sinks[1]->set_pattern("[%D %T.%f%z] [%l] [%s|%!|%#] %v");
    
    spdlog::init_thread_pool(512, 1);
    
    juniper_logger = std::make_shared<spdlog::async_logger>("Juniper", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::overrun_oldest);
    spdlog::register_logger(juniper_logger);
    juniper_logger->set_level(spdlog::level::trace);
    juniper_logger->flush_on(spdlog::level::trace);
    
    spdlog::set_default_logger(juniper_logger);
}

void Logger::cleanup() {
    spdlog::shutdown();
}
