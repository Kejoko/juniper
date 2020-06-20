//======================================================================
// App.h
//
// Keegan Kochis
// Created: 2020/6/19
// The class to be extended by Juniper applications
//======================================================================

#ifndef APP_H
#define APP_H

#include <string>

class App {
public:
    App(std::string title, int fps);
    
    void init();
    void run();
    void stop();
    
    bool is_running() { return running; };
    std::string get_title() { return title; };
    int get_fps() { return fps; };
private:
    bool running;
    std::string title;
    int fps;
};

#endif // APP_H
