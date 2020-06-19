//======================================================================
// logger.h
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages
//======================================================================

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    //  Log to console
    static void log_info(std::string text);
    static void log_warning(std::string text);
    static void log_error(std::string text);
};

#endif // LOGGER_H
