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
#include <Logger.h>

#include "App.h"

std::thread log_thread;

App::App(std::string _title, int ms_timestep) {
    title = _title;
    delta_time = duration_ms{ms_timestep};
}

void App::init() {
    logger.console(log_info, "Initializing " + title);
    logger.init(title);
    running = true;
    log_thread = std::thread(&Logger::consumeMessage, &logger);
    logger.console(log_info, "Initialized " + title);
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
void App::run() {
    init();
    logger.console(log_fatal, "Testing fatalaity message");
    
    time_point previous_tick_start = highres_clock::now();
    time_point current_tick_start;
    
    duration_ns elapsed_tick_time;
    duration_ns accumulator = duration_ns{0};
    
    // Previous state declaration
    // Current state declaration
    // Next state declaration
    
    long double alpha;
    
    logger.console(log_info, "Starting " + title);
    int count = 0;
    while(running && count < 1000000000) {
        current_tick_start = highres_clock::now();
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
            logger.produceMessage(log_info, FUNC_STRING, std::to_string(count));
        }
        
        alpha = (accumulator.count() / delta_time.count()) / + 1000000.0;
        
        // Update current state by interpolating between previous and next state
        // current state  =  next_state * alpha  +  prev_state * (1 - alpha)
        
        // Render current state
        
        count++;
    }
    
    cleanup();
}

void App::cleanup() {
    logger.console(log_warn, "Cleaning up all resources");
    logger.cleanup();
    logger.console(log_info, "successful cleanup");
}
