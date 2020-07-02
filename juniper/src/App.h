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

#include <Core.h>

#include <GLFW/glfw3.h>

#include <World.h>

typedef std::chrono::high_resolution_clock highres_clock;
typedef highres_clock::time_point time_point;
typedef std::chrono::duration<signed long long, std::nano> duration_ns;
typedef std::chrono::duration<signed long long, std::milli> duration_ms;

namespace Juniper {

    class App {
    public:
        App(std::string _title, int ticks_per_second);

        bool init();
        bool run();
        bool cleanup();

        bool should_run() { return running && !glfwWindowShouldClose(game_window); };

        std::string get_title() { return title; };
        bool is_running() { return running; };
        GLFWwindow* get_game_window() { return game_window;  };
    private:
        std::string title;

        bool running = false;

        duration_ns game_time = duration_ns{0};
        duration_ms delta_time;
        
        GLFWwindow* game_window;

        World* world;
    };

}

#endif // APP_H
