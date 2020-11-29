#ifndef TEXAS_TRAIL_UI_FORK_H
#define TEXAS_TRAIL_UI_FORK_H
#include "world/Path.h"
#include "world/RoadFork.h"

class UI;
class TexasTrail;
class UIFork {
    public:
        UIFork(TexasTrail& game, RoadFork& fork, UI& ui);
        virtual ~UIFork();

        Path* run();

    private:
        RoadFork& _fork;
        TexasTrail& _game;
        UI& _ui;
};

#endif