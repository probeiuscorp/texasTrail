#ifndef TEXAS_TRAIL_UI_CITY_H
#define TEXAS_TRAIL_UI_CITY_H
#include "world/City.h"
#include "TexasTrail.h"
#include "DialoguePrompt.h"
#include "TablePrompt.h"
#include "UIShop.h"

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

        void virtual run();
        void virtual setUIHome();
        void virtual setUIChooseShop();

    private:
        TexasTrail& _game;
        City& _city;
        const UI& _ui;
};

#endif