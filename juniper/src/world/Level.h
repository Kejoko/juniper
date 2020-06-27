//==========================================================================================
// Level.h
//
// Keegan Kochis
// Created: 2020/6/19
// The class represents a level of the game world. The levels are all
// distinct from eachother in that they are all loaded with mutual
// exclusion. That is one level is loaded at a time.
//==========================================================================================

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include <Chunk.h>

namespace Juniper {

    class Level {
    public:
        Level(std::string _name);
        
        std::vector<Chunk> chunks;
        
        std::string get_name() { return name; };
    private:
        std::string name;
    };

}

#endif // LEVEL_H
