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

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <Core.h>

#include "Logger.h"

std::shared_ptr<spdlog::logger> Logger::juniper_logger;
std::shared_ptr<spdlog::logger> Logger::app_logger;

void Logger::init(std::string title) {
    spdlog::sink_ptr j_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    juniper_logger = std::make_shared<spdlog::logger>("Juniper", j_sink);
    juniper_logger->set_pattern("[%T.%F] [%^%s|%!|%#%$] %v");
    
    spdlog::sink_ptr a_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(title + "-log.txt", true);
    app_logger = std::make_shared<spdlog::logger>("Application", a_sink);
    app_logger->set_pattern("[%D %T.%f %z] [%l] [%s|%!|%#] %v");
}

void Logger::cleanup() {
    spdlog::shutdown();
}
