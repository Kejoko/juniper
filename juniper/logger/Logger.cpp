//==========================================================================================
// Logger.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages using spdlog
//==========================================================================================

#include <iostream>
#include <memory>
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
        #define CRIT(s) { \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); \
            std::cout << "[CRIT.]"; \
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
        #define CRIT(s) {\
            std::cout << BACKRED << "[CRIT.]" << RESET << "\t" <<  s << "\n"; \
        }
    #endif // UNIX_BUILD
#elif defined RELEASE
    #define INFO(s) {}
    #define WARN(s) {}
    #define ERROR(s) {}
    #define CRIT(s) {}
#endif

std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Logger::juniper_logger;
std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Logger::app_logger;

void Logger::init() {
    
}

void Logger::c_info(std::string text) { INFO(text); }
void Logger::c_warn(std::string text) { WARN(text); }
void Logger::c_error(std::string text) { ERROR(text); }
void Logger::c_crit(std::string text) { CRIT(text); }
