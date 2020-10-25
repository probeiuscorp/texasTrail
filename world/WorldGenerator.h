#ifndef TEXAS_TRAIL_WORLD_GENERATOR_H
#define TEXAS_TRAIL_WORLD_GENERATOR_H
#include "World.h"
#include "City.h"
#include "Path.h"
#include "Biomes.h"

class WorldGenerator {
    public:
        WorldGenerator();
        virtual ~WorldGenerator();

        virtual World* generateWorld();
};

#endif