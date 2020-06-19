//======================================================================
// logger.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Logging messages
//======================================================================

#include <iostream>
#include <string>

#incluede "logger.h"

// Define colors here (dependent upon OS)

#ifndef RELEASE
    #define INFO(s) { \
        std::cout << "[info]" << s << "\n"; \
    }
    #define WARNING(s) { \
        std::cout << "[warning]" << s << "\n"; \
    }
    #define ERROR(s)  \
        std::cout << "[error]" << s << "\n"; \
    }
#elif
    #define INFO(s) {}
    #define WARNING(s) {}
    #define ERROR(s) {}
#endif

void Logger::log_info(std::string text) {
    INFO(text);
}

void Logger::log_warning(std::string text) {
    WARNING(text);
}

void Logger::log_error(std::string text) {
    ERROR(text);
}
