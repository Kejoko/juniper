//======================================================================
// App.cpp
//
// Keegan Kochis
// Created: 2020/6/19
// The class to be extended by Juniper applications
//======================================================================

#include <string>

#include "App.h"

App::App(std::string _title, int _fps) {
    title = _title;
    fps = _fps;
}

void App::init() {
    running = true;
}

void App::run() {
    
}

void App::stop() {
    
}