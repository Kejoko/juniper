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
//    spdlog::register_logger(juniper_logger);
    
    spdlog::sink_ptr a_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(title + "-log.txt", true);
    app_logger = std::make_shared<spdlog::logger>("Application", a_sink);
//    spdlog::register_logger(app_logger);
    
    
    
//    std::vector<spdlog::sink_ptr> sinks;
//    sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
//    sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>(title + "-log.txt", true));
//
//    juniper_logger = std::make_shared<spdlog::logger>("Juniper", begin(sinks), end(sinks));
//    spdlog::register_logger(juniper_logger);
//    app_logger = std::make_shared<spdlog::logger>("Application", begin(sinks), end(sinks));
//    spdlog::register_logger(app_logger);

    
    
    
//    auto j_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("juniper-log.txt");
//    juniper_file_logger = j_sink;
//    spdlog::register_logger(juniper_file_logger);
    
//    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
//    juniper_console_logger = console_sink;
//
//    auto app_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(title + "-log.txt");
//    app_file_logger = app_sink;
}
