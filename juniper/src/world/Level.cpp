//==========================================================================================
// Level.cpp
//
// Keegan Kochis
// Created: 2020/6/19
// The class represents a level of the game world. The levels are all
// distinct from eachother in that they are all loaded with mutual
// exclusion. That is one level is loaded at a time.
//==========================================================================================

#include <string>

#include "Level.h"

Level::Level(std::string _name) {
    name = _name;
}
