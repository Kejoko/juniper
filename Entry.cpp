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
    Juniper::Logger::init(title);
    
    Juniper::App* game = new Juniper::App(title, 4);
    (*game).run();
    
    Juniper::Logger::cleanup();
    
    return 0;
}
