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
#include <thread>

#include <Core.h>

enum log_type { log_info, log_warn, log_error, log_fatal };

class Logger {
public:
    void init(std::string title);
    void console(int type, std::string text);
    void produceMessage(int type, std::string function, std::string text);
    void consumeMessages();
    void cleanup();
private:
    bool initialized;
    bool running;
    std::ofstream log_file;
    std::string messages[20];
    int first = 0;
    int count = 0;
};

extern Logger logger;
extern std::thread logger_thread;

#endif // LOGGER_H
