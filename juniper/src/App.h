//==========================================================================================
// App.h
//
// Keegan Kochis
// Created: 2020/6/19
// The class to be extended by Juniper applications
//==========================================================================================

#ifndef APP_H
#define APP_H

#include <chrono>
#include <string>
#include <thread>

#include <World.h>

typedef std::chrono::high_resolution_clock highres_clock;
typedef highres_clock::time_point time_point;
typedef std::chrono::duration<signed long long, std::nano> duration_ns;
typedef std::chrono::duration<signed long long, std::milli> duration_ms;

namespace Juniper {

    class App {
    public:
        World* world;
        
        App(std::string _title, int ticks_per_second);
        
        void init();
        int run();
        void cleanup();
        
        bool is_running() { return running; };
        std::string get_title() { return title; };
    private:
        bool running = false;
        std::string title;
        
        duration_ns game_time = duration_ns{0};
        duration_ms delta_time;
        
    };

}

#endif // APP_H
