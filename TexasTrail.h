#ifndef TEXAS_TRAIL_H
#define TEXAS_TRAIL_H
#include "Settings.h"
#include "Party.h"
#include "world/City.h"
#include "world/World.h"
#include "world/WorldGenerator.h"
#include "DialoguePrompt.h"
#include "Log.h"
#include "Colors.h"
#include <string>
#include <vector>
#include <stdio.h>

// using std::string;
// using std::vector;

class TexasTrail {
    public:
        using StringList = std::vector<std::string>;
        using Difficulty = Settings::Difficulty;

    public: 
        TexasTrail();
        virtual ~TexasTrail();

        void setDifficulty(Difficulty difficulty);
        void setWorld(World* world);
        Difficulty getDifficulty();
        Party& getParty();
        World* generateWorld();
        City& startingCity();
        void tick(int hours);

    private: 
        World* _world;
        Settings _settings;
        Party _party;
};

#endif