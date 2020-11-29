#ifndef TEXAS_TRAIL_UI_H
#define TEXAS_TRAIL_UI_H
#include "DialoguePrompt.h"
#include "TexasTrail.h"
#include "Settings.h"
#include "StringPrompt.h"
#include "Log.h"
#include "world/City.h"
#include "world/RoadFork.h"
#include "UICity.h"
#include "UIGoal.h"
#include "UIFork.h"
#include "UITravel.h"
#include <string>

using StringList = DialoguePrompt::StringList;
using Difficulty = Settings::Difficulty;

// class TexasTrail;

class UI {
    public:
        enum class Menu {
            MAIN,
            LOAD,
            NEW_GAME,
            PARTY,
            TIME_OF_YEAR,
        };
    public:
        UI(TexasTrail& game);
        virtual ~UI();

        virtual Menu getUI();
        virtual int init();
        virtual void setUIMain();
        virtual void setUILoad();
        virtual void setUINewGame();
        virtual void setUIParty();
        virtual void setUIConfirmNewGame();
        virtual void setUIGame();
        virtual void setUILoop();
        virtual void printTitle() const;
        virtual void clean() const;

        virtual void exit();
        virtual void exit(int exit_status);

    private:
        int _exit_status;
        bool _exit = false;
        Menu _menu;
        TexasTrail& _game;
        StringList _names;
};

#endif