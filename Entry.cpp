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
    
    App* game = new App("Title", 4);
    (*game).run();
    
    return 0;
}
