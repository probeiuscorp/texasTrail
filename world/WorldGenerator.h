#ifndef TEXAS_TRAIL_WORLD_GENERATOR_H
#define TEXAS_TRAIL_WORLD_GENERATOR_H
#include "World.h"

class WorldGenerator {
    public:
        WorldGenerator();
        virtual ~WorldGenerator();

        void virtual generateWorld();
};

#endif