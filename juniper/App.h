//==========================================================================================
// App.h
//
// Keegan Kochis
// Created: 2020/6/19
// The class to be extended by Juniper applications
//==========================================================================================

#ifndef APP_H
#define APP_H

#include <string>

#include <World.h>

typedef std::chrono::high_resolution_clock highres_clock;
typedef highres_clock::time_point time_point;
typedef std::chrono::duration<signed long long, std::nano> duration_ns;
typedef std::chrono::duration<signed long long, std::milli> duration_ms;

class App {
public:
    World* world;
    
    App(std::string _title, int _step);
    
    void init();
    void run();
    void stop();
    
    bool is_running() { return running; };
    std::string get_title() { return title; };
    int get_step() { return step; };
private:
    bool running = false;
    std::string title;
    int step;
};

#endif // APP_H
