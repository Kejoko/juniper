//======================================================================
// Entry.cpp
//
// Keegan Kochis
// Created: 2020/6/18
// Entry point to the application created with the Juniper engine
//======================================================================

#include <iostream>
#include <string>

#include <Juniper.h>

int main() {
    std::string title = "Demo";
    Logger::init(title);
    
    App* game = new App(title, 4);
    (*game).run();
    
    Logger::cleanup();
    
    return 0;
}
