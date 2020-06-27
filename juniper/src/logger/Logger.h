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

#include <Core.h>

#include <spdlog/async.h>
#include <spdlog/spdlog.h>

class Logger {
public:
    static void init(std::string title);
    static void cleanup();
private:
    static std::shared_ptr<spdlog::async_logger> juniper_logger;
};

#define JUNIPER_TRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define JUNIPER_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define JUNIPER_WARN(...) SPDLOG_WARN(__VA_ARGS__)
#define JUNIPER_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define JUNIPER_CRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)
#define JUNIPER_FATAL(...) SPDLOG_FATAL(__VA_ARGS__)

#endif // LOGGER_H
