#ifndef TEXAS_TRAIL_UI_CITY_H
#define TEXAS_TRAIL_UI_CITY_H
#include "world/City.h"
#include "TexasTrail.h"

class UICity {
    public: 
        UICity(TexasTrail& game, City& city);
        virtual ~UICity();

    private:
        TexasTrail& _game;
        City& _city;
};

#endif