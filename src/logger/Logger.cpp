//======================================================================
// logger.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages
//======================================================================

#include <iostream>
#include <string>

#include "logger.h"

#ifdef DEBUG
// IF WINDOWS
    #ifdef _WIN32
        #include <Windows.h>
        #define INFO(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << "[INFO]\t"; \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << s << "\n"; \
        }
        #define WARN(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); \
            std::cout << "[WARN]\t"; \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << s << "\n"; \
        }
        #define ERROR(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); \
            std::cout << "[ERROR]\t"; \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
            std::cout << s << "\n"; \
        }
    #endif // _WIN32
    #if defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
        #define RESET   "\033[0m"
        #define WHITE   "\033[97m"
        #define GREEN   "\033[92m"
        #define YELLOW  "\033[93m"
        #define RED     "\033[91m"
        #define INFO(s) { \
            std::cout << "[INFO]\t" << RESET << s << "\n"; \
        }
        #define WARN(s) { \
            std::cout << YELLOW << "[WARN]\t" << RESET << s << "\n"; \
        }
        #define ERROR(s) { \
            std::cout << RED << "[ERROR]\t" << RESET << s << "\n"; \
        }
    #endif // UNIX
#elif RELEASE
    #define INFO(s) {}
    #define WARN(s) {}
    #define ERROR(s) {}
#endif

void Logger::info(std::string text) {
    INFO(text);
}

void Logger::warn(std::string text) {
    WARN(text);
}

void Logger::error(std::string text) {
    ERROR(text);
}
