#ifndef TEXAS_TRAIL_UI_CITY_H
#define TEXAS_TRAIL_UI_CITY_H
#include "DialoguePrompt.h"
#include "TablePrompt.h"
#include "ui/UIShop.h"
#include "ui/UICommons.h"
#include "world/Path.h"
#include "Utils.h"

class UI;
class City;
class TexasTrail;
class UICity {
    public:
        using StringList = std::vector<std::string>;
    public: 
        UICity(TexasTrail& game, City& city, UI& ui);
        virtual ~UICity();

        virtual Path* run();
        virtual bool setUIHome();
        virtual void setUIChooseShop();
        virtual Path* setUIChooseNextPath();

    private:
        TexasTrail& _game;
        City& _city;
        UI& _ui;
};

#endif