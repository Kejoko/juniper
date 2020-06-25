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

#include <Core.h>

enum log_type { log_info, log_warn, log_error, log_fatal };

class Logger {
public:
    void init(std::string title);
    void console(int type, std::string text);
    void produceMessage(int type, std::string function, std::string text);
    void consumeMessage();
    void cleanup();
private:
    bool running = false;
    std::ofstream log_file;
};

extern Logger logger;

#endif // LOGGER_H
