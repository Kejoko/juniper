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
    static void info(std::string text);
    static void warn(std::string text);
    static void error(std::string text);
};

#endif // LOGGER_H
