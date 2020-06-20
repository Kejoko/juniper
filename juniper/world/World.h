//==========================================================================================
// World.h
//
// Keegan Kochis
// Created: 2020/6/20
// The class represents the game world. It contains all of the different
// levels
//==========================================================================================

#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>

#include <Level.h>

class World {
public:
    World(std::string _name);
    
    std::vector<Level> levels;
    
    std::string get_name();
private:
    std::string name;
};

#endif // WORLD_H
