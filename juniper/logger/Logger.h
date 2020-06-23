//==========================================================================================
// logger.h
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages
//==========================================================================================

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

enum log_type { log_info, log_warn, log_error, log_fatal };

class Logger {
public:
    void init(std::string title);
    void console(int type, std::string text);
    void file(int type, std::string text);
    void cleanup();
private:
    bool initialized;
    std::ofstream log_file;
};

extern Logger logger;

#endif // LOGGER_H
