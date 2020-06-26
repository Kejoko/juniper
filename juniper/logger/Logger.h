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

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <Core.h>

class Logger {
public:
    static void init(std::string title);
    
    static std::shared_ptr<spdlog::logger>& get_juniper_logger() { return juniper_logger; }
    static std::shared_ptr<spdlog::logger>& get_app_logger() { return app_logger; }
    
private:
    static std::shared_ptr<spdlog::logger> juniper_logger;
    static std::shared_ptr<spdlog::logger> app_logger;
};

#ifdef DEBUG
#define JUNIPER_INFO(...) Logger::get_juniper_logger()->info(__VA_ARGS__)
#define JUNIPER_WARN(...) Logger::get_juniper_logger()->warn(__VA_ARGS__)
#define JUNIPER_ERROR(...) Logger::get_juniper_logger()->error(__VA_ARGS__)
#define JUNIPER_CRITICAL(...) Logger::get_juniper_logger()->critical(__VA_ARGS__)
#define JUNIPER_FATAL(...) Logger::get_juniper_logger()->fatal(__VA_ARGS__)
#endif // DEBUG
#ifdef RELEASE
#define JUNIPER_INFO(...)
#define JUNIPER_WARN(...)
#define JUNIPER_ERROR(...)
#define JUNIPER_CRITICAL(...)
#define JUNIPER_FATAL(...)
#endif // RELEASE

#define APP_INFO(...) Logger::get_app_logger()->info(__VA_ARGS__)
#define APP_WARN(...) Logger::get_app_logger()->warn(__VA_ARGS__)
#define APP_ERROR(...) Logger::get_app_logger()->error(__VA_ARGS__)
#define APP_CRITICAL(...) Logger::get_app_logger()->critical(__VA_ARGS__)
#define APP_FATAL(...) Logger::get_app_logger()->fatal(__VA_ARGS__)

#endif // LOGGER_H
