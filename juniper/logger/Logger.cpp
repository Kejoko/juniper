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
}

void Logger::console(int type, std::string text) {
    switch(type) {
        case log_info: INFO(text); break;
        case log_warn: WARN(text); break;
        case log_error: ERROR(text); break;
        case log_fatal: FATAL(text); break;
    }
}

void Logger::file(int type, std::string function, std::string text) {
    // Log current time in nanoseconds resolution
    std::string message = "";
    
    // Log level
    switch(type) {
        case log_info: message += "\tinfo.\t"; break;
        case log_warn: message += "\twarn\t"; break;
        case log_error: message += "\terror\t"; break;
        case log_fatal: message += "\tfatal\t"; break;
    }
    
    // Log calling function
    
    // Log the message
    
    // Write
}

void Logger::cleanup() {
    log_file.close();
}
