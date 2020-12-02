#ifndef TEXAS_TRAIL_UI_SHOP_H
#define TEXAS_TRAIL_UI_SHOP_H
#include "Shop.h"
#include "DialoguePrompt.h"
#include "TablePrompt.h"
#include "Utils.h"
#include "IntPrompt.h"
#include "UI.h"

class UI;
class TexasTrail;
class UIShop {
    public:
        enum class Return {
            CONTINUE,
            SAVE_AND_EXIT
        };

    public:
        using StringList = std::vector<std::string>;

    public: 
        UIShop(TexasTrail& game, Shop& shop, UI& ui);
        virtual ~UIShop();

        void virtual run();
        void virtual setUIPickItem();
        void virtual setUIPickCount(int index, Shop::EnumShopRet prevRet);

    private:
        TexasTrail& _game;
        Shop& _shop;
        UI& _ui;
};

#endif