#ifndef TEXAS_TRAIL_UI_CITY_H
#define TEXAS_TRAIL_UI_CITY_H
#include "DialoguePrompt.h"
#include "TablePrompt.h"
#include "UIShop.h"
#include "UI.h"

class UI;
class City;
class TexasTrail;
class UICity {
    public:
        enum class Return {
            CONTINUE,
            SAVE_AND_EXIT
        };
    public:
        using StringList = std::vector<std::string>;
    public: 
        UICity(TexasTrail& game, City& city, const UI& ui);
        virtual ~UICity();

        Return virtual run();
        Return virtual setUIHome();
        void virtual setUIChooseShop();

    private:
        TexasTrail& _game;
        City& _city;
        const UI& _ui;
};

#endif