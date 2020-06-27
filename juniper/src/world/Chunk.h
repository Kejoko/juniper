//==========================================================================================
// Chunk.h
//
// Keegan Kochis
// Created: 2020/6/20
// The class represents a chunk in a game level. Each chunk represents a square
// area of the game world.
//==========================================================================================

#ifndef CHUNK_H
#define CHUNK_H

//  Store terrain and game-object/world-asset information

namespace Juniper {

    class Chunk {
    public:
        Chunk(int _id, int _x, int _y);
    private:
        int id;
        int x;
        int y;
    };

}

#endif // CHUNK_H
