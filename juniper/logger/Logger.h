//==========================================================================================
// Logger.h
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages using spdlog
//==========================================================================================

#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <string>

#include <spdlog/sinks/basic_file_sink.h>

#include <Core.h>

class Logger {
public:
    static void init();
    static void c_info(std::string text);
    static void c_warn(std::string text);
    static void c_error(std::string text);
    static void c_crit(std::string text);
    
    
private:
    static std::shared_ptr<spdlog::sinks::basic_file_sink_mt> juniper_logger;
    static std::shared_ptr<spdlog::sinks::basic_file_sink_mt> app_logger;
};

#define JUNIPER_INFO(...)
#define JUNIPER_WARN(...)
#define JUNIPER_ERROR(...)
#define JUNIPER_CRITICAL(...)

#define APP_INFO(...)
#define APP_WARN(...)
#define APP_ERROR(...)
#define APP_CRITICAL(...)

#endif // LOGGER_H
