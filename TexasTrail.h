#ifndef TEXAS_TRAIL_H
#define TEXAS_TRAIL_H
#include <string>
#include <vector>
#include "Settings.h"
#include "UI.h"
#include "Party.h"
#include "world/World.h"
#include "world/WorldGenerator.h"

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
        Difficulty getDifficulty();
        Party& getParty();
        World& generateWorld();

    private: 
        Settings _settings;
        Party _party;
};

#endif