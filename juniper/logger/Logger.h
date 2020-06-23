//==========================================================================================
// logger.h
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages
//==========================================================================================

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

enum log_type { log_info, log_warn, log_error, log_fatal };

class Logger {
public:
    static void console(int type, std::string text);
//    static void file(int type, std::string text);
};

#endif // LOGGER_H
