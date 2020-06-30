//==========================================================================================
// App.cpp
//
// Keegan Kochis
// Created: 2020/6/19
// The class to be extended by Juniper applications
//==========================================================================================

#include <chrono>
#include <string>
#include <thread>

#include <Core.h>

#include <GLFW/glfw3.h>

#include <Logger.h>

#include "App.h"

namespace Juniper {

    App::App(std::string _title, int ms_timestep) {
        title = _title;
        delta_time = duration_ms{ms_timestep};
    }

    void App::init() {
        running = true;
    }


    //------------------------------------------------------------------------------------------
    // Main game loop. Run at constant time step with variable rate
    // rendering.
    //
    // Render as fast as possible (the outer while loop). The current state to render is determined
    // by the previous state, the next state, and the time that remains until the next state. The
    // current state is calculated by determining what percentage of the way to the next tick we
    // have completed. The alpha value is divided by 1 million to convert from nanosecond duration
    // to millisecond duration.
    // The inner while loop determines how frequently the game ticks occur. These game ticks are
    // when the previous state and next state are to be updated according to the game world's
    // behavior.
    //
    // App.h has some handy typedefs which provide highres_clock, time_point, duration_ns,
    // and duration_ms. Each type is defined as something from the chrono library.
    //------------------------------------------------------------------------------------------
    int App::run() {
        init();
        
        time_point previous_tick_start = highres_clock::now();
        time_point current_tick_start;
        
        duration_ns elapsed_tick_time;
        duration_ns accumulator = duration_ns{0};
        
        // Previous state declaration
        // Current state declaration
        // Next state declaration
        
        long double alpha;
        
        GLFWwindow* window;
        
        if (!glfwInit()) {
            JUNIPER_CRITICAL("Failed to initialize glfw");
            return -1;
        }
        
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window) {
            glfwTerminate();
            return -1;
        }
        
        glfwMakeContextCurrent(window);
        
        while(running && !glfwWindowShouldClose(window)) {
            current_tick_start = highres_clock::now();
            elapsed_tick_time = current_tick_start - previous_tick_start;
            // Clamp tick time if too long
            previous_tick_start = current_tick_start;
            
            accumulator += elapsed_tick_time;
            
            // Handle input
            
            while(accumulator >= delta_time) {
                // Update previous state to be the previous next state, prev state = next state
                // Determine next state (physics and game world behavior, etc...)
                game_time += delta_time;
                accumulator -= delta_time;
            }
            
            alpha = (accumulator.count() / delta_time.count()) / + 1000000.0;
            
            // Update current state by interpolating between previous and next state
            // current state  =  next_state * alpha  +  prev_state * (1 - alpha)
            
            // Render current stateglClear
            (GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        
        glfwTerminate();
        cleanup();
        return 0;
    }

    void App::cleanup() {
        
    }

}
