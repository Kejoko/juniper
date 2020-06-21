//==========================================================================================
// App.cpp
//
// Keegan Kochis
// Created: 2020/6/19
// The class to be extended by Juniper applications
//==========================================================================================

#include <chrono>
#include <string>

#include <Logger.h>

#include "App.h"

App::App(std::string _title, int _step) {
    title = _title;
    step = _step;
}

void App::init() {
    Logger::info("Initializing " + title);
    running = true;
    Logger::info("Initialized " + title);
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
//------------------------------------------------------------------------------------------
void App::run() {
    init();
    
    std::chrono::duration<signed long long, std::nano> game_time = std::chrono::duration<signed long long, std::nano>{0};
    std::chrono::duration<signed long long, std::milli> delta_time = std::chrono::duration<signed long long, std::milli>{4};
    
    std::chrono::high_resolution_clock::time_point previous_tick_start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point current_tick_start;
    
    std::chrono::duration<signed long long, std::nano> elapsed_tick_time;
    std::chrono::duration<signed long long, std::nano> accumulator = std::chrono::duration<signed long long, std::nano>{0};
    
    // Previous state
    // Current state
    // Next state
    
    long double alpha;
    
    Logger::info("Starting " + title);
    while(running) {
        current_tick_start = std::chrono::high_resolution_clock::now();
        elapsed_tick_time = current_tick_start - previous_tick_start;
        // If elapsed tick time was too long, lock it
        previous_tick_start = current_tick_start;
        
        accumulator += elapsed_tick_time;
        
        // Handle input
        
        while(accumulator >= delta_time) {
            // Update previous state to be the previous next state, prev state = next state
            // Determine next state (physics and game world behavior, etc...)
            game_time += delta_time;
            accumulator -= delta_time;
        }
        
        alpha = (accumulator.count() / delta_time.count()) / 1000000.0;
        
        // Update current state by interpolating between previous and next state
        // current state  =  next_state * alpha  +  prev_state * (1 - alpha)
        
        // Render current state
    }
    
    Logger::warn("Stopped " + title);
}

void App::stop() {
    
}
