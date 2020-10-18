#ifndef TEXAS_TRAIL_UI_TRAVEL_H
#define TEXAS_TRAIL_UI_TRAVEL_H
#include "TexasTrail.h"
#include "UI.h"
#include "Utils.h"
#include <string>
using std::string;

class UI;
class UITravel {
    public:
        UITravel(TexasTrail& game, const UI& ui);
        virtual ~UITravel();
    
        void run();

    private:
        void setUITravel();
    
    private:
        TexasTrail& _game;
        const UI& _ui;
};

#endif