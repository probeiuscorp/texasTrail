#ifndef TEXAS_TRAIL_H
#define TEXAS_TRAIL_H
#include "Settings.h"
#include "Party.h"
#include "world/City.h"
#include "world/World.h"
#include "world/WorldGenerator.h"
#include "DialoguePrompt.h"
#include "Log.h"
#include "Date.h"
#include <string>
#include <vector>
#include <stdio.h>
using std::string;
using std::vector;

class TexasTrail {
    public:
        using StringList = std::vector<std::string>;
        using Difficulty = Settings::Difficulty;

    public: 
        TexasTrail();
        virtual ~TexasTrail();

        City& startingCity();
        World* generateWorld();
        void tick(int hours);

        void setDifficulty(Difficulty difficulty) { _settings.setDifficulty(difficulty); }
        void setWorld(World* world) { _world = world; }
        void setTime(int hour, int day, int month, int year) { _date.setTime(hour, day, month, year); }
        Difficulty getDifficulty() const { return _settings.getDifficulty(); }
        Party& getParty() { return _party; }
        World* getWorld() const { return _world; }
        const Date& date() const { return _date; }
        string formattedTime() const { return _date.formattedTime(); }

    private: 
        World* _world;
        Settings _settings;
        Party _party;
        Date _date;
};

#endif