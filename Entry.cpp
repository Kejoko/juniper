//======================================================================
// Entry.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Entry point to the application created with the Juniper engine
//======================================================================

#include <iostream>
#include <string>

#include "juniper/Juniper.h"

int main() {
    std::cout << "Welcome to the juniper engine!\n";
    
    App game("J-Game", 120);
    game.init();
    
    Logger::info(game.get_title());
    if (game.is_running())
        Logger::warn("Initialized");
    else
        Logger::warn("Not initialized");
    
    return 0;
}
