//==========================================================================================
// App.cpp
//
// Keegan Kochis
// Created: 2020/6/19
// The class to be extended by Juniper applications
//==========================================================================================

#include <string>

#include "App.h"

App::App(std::string _title, int _step) {
    title = _title;
    step = _step;
}

void App::init() {
    running = true;
}


//------------------------------------------------------------------------------------------
// Main game loop. Run at constant time step with variable rate
// rendering.
//------------------------------------------------------------------------------------------
void App::run() {
    init();
    
    // Game time counter, starting at 0
    // Delta time (how much time between physics updates)
    
    while(running) {
        // Get current time (only once per frame for consistency) as start time for this frame
        // Use start time and previous start time to determine previous frame duration
        // Lock the duration of the last frame if it was too long
        
        // Update accumulated time by adding the frame time
        
        // Handle input
        // Update game physics
        
        // While accumulated time is greater than the delta time
            // Update game states
            // Update time counter by delta time
            // Decreate accumulated time by delta time
        
        // Determine remaining time in frame (alpha = accumulated time / delta time)
        
        // Update state according to remaining time
        
        // Render state
    }
    
}

void App::stop() {
    
}
