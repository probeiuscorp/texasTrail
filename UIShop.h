#ifndef TEXAS_TRAIL_UI_SHOP_H
#define TEXAS_TRAIL_UI_SHOP_H
#include "Shop.h"
#include "TexasTrail.h"
#include "DialoguePrompt.h"

class UIShop {
    public:
        enum class Return {
            CONTINUE,
            SAVE_AND_EXIT
        };
    public:
        using StringList = std::vector<std::string>;
    public: 
        UIShop(TexasTrail& game, Shop& shop);
        virtual ~UIShop();

        void virtual run();

    private:
        TexasTrail& _game;
        Shop& _shop;
};

#endif