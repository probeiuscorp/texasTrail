#ifndef TEXAS_TRAIL_UI_CITY_H
#define TEXAS_TRAIL_UI_CITY_H
#include "DialoguePrompt.h"
#include "TablePrompt.h"
#include "UIShop.h"
#include "UICommons.h"
#include "world/Path.h"

class UI;
class City;
class TexasTrail;
class UICity {
    public:
        using StringList = std::vector<std::string>;
    public: 
        UICity(TexasTrail& game, City& city, const UI& ui);
        virtual ~UICity();

        virtual Path* run();
        virtual bool setUIHome();
        virtual void setUIChooseShop();
        virtual Path* setUIChooseNextPath();

    private:
        TexasTrail& _game;
        City& _city;
        const UI& _ui;
};

#endif