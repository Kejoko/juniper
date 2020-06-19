//======================================================================
// Entry.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Entry point to the application created with the Juniper engine
//======================================================================

#include <iostream>

#include "juniper/logger/logger.h"

int main() {
    std::cout << "Welcome to the juniper engine!\n";
    Logger::info("Testing");
    Logger::warn("Testing");
    Logger::error("Testing");
    return 0;
}
