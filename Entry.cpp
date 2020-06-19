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
    Logger::log_info("Testing");
    //INFO("TESTING DIRECT");
    return 0;
}
