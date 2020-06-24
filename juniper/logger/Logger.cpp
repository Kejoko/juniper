//==========================================================================================
// logger.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages
//==========================================================================================

#include <fstream>
#include <iostream>
#include <string>

#include <Core.h>

#include "Logger.h"

#ifdef DEBUG
    #ifdef WINDOWS_BUILD
        #include <Windows.h>
        #define INFO(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << "[INFO.]"; \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << "\t" <<  s << "\n"; \
        }
        #define WARN(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); \
            std::cout << "[WARN.]"; \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << "\t" <<  s << "\n"; \
        }
        #define ERROR(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); \
            std::cout << "[ERROR]"; \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << "\t" <<  s << "\n"; \
        }
        #define FATAL(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); \
            std::cout << "[FATAL]"; \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << "\t" << s << "\n"; \
        }
    #endif // WINDOWS_BUILD
    #ifdef UNIX_BUILD
        #define RESET   "\033[0m"
        #define WHITE   "\033[97m"
        #define GREEN   "\033[92m"
        #define YELLOW  "\033[93m"
        #define RED     "\033[91m"
        #define BACKRED "\033[101m"
        #define INFO(s) { \
            std::cout << "[INFO.]" << RESET << "\t" <<  s << "\n"; \
        }
        #define WARN(s) { \
            std::cout << YELLOW << "[WARN.]" << RESET << "\t" <<  s << "\n"; \
        }
        #define ERROR(s) { \
            std::cout << RED << "[ERROR]" << RESET << "\t" <<  s << "\n"; \
        }
        #define FATAL(s) {\
            std::cout << BACKRED << "[FATAL]" << RESET << "\t" <<  s << "\n"; \
        }
    #endif // UNIX_BUILD
#elif defined RELEASE
    #define INFO(s) {}
    #define WARN(s) {}
    #define ERROR(s) {}
#endif

Logger logger;

void Logger::init(std::string title) {
    log_file.open(title + ".log");
    // Initialize messages to be character arrays with a fixed number of characters.
    running = true;
}

void Logger::console(int type, std::string text) {
    switch(type) {
        case log_info: INFO(text); break;
        case log_warn: WARN(text); break;
        case log_error: ERROR(text); break;
        case log_fatal: FATAL(text); break;
    }
}

//------------------------------------------------------------------------------------------
// This is the method utilized in the main thread to produce a message for the log file.
// The message will be added to the bounded buffer, messages, before it is written to the
// file by Logger::consumeMessage, running in a seperate thread.
//
// The message is added to the buffer at first+count, then count is incremented to indicate
// another message has been added to the buffer.
//
// Currently, it is assumed that there will always be room in the buffer to add a message.
// We are currently not handling the case where the buffer is full. In the case that the
// buffer is full, the oldest message will be overwritten.
//------------------------------------------------------------------------------------------
void Logger::produceMessage(int type, std::string function, std::string text) {
    std::string msg = "YYYY-MM-DD HH:MM:SS.999999999"; // Get current time nanoseconds res
    
    switch(type) {
        case log_info: msg += "\tinfo.\t"; break;
        case log_warn: msg += "\twarn\t"; break;
        case log_error: msg += "\terror\t"; break;
        case log_fatal: msg += "\tfatal\t"; break;
    }
    
    msg += function;
    #ifdef WINDOWS_BUILD
    msg += "\r";
    #endif
    msg += "\n\t\t" + text;
    
    messages[first + count] = msg;
    count = (count + 1) % 20;
}

//------------------------------------------------------------------------------------------
// This method is responsible for taking a message from the messages buffer and writing it
// to the log file. The messages are produced in the main thread and this function is run in
// a different thread. The messages are being added to the buffer at inIndex by the
// Logger::produceMessage method in a seperate thread.
//
// The messages are being removed from the buffer at outIndex and written to the member
// file, log_file, which was initialized in Logger::init.
//------------------------------------------------------------------------------------------
void Logger::consumeMessages() {
    while(running) {
        if (count > 0) {
            log_file << messages[first];
            first++;
            count--;
        }
    }
}

void Logger::cleanup() {
    running = false;
    log_file.close();
}
