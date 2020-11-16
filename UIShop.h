#ifndef TEXAS_TRAIL_UI_SHOP_H
#define TEXAS_TRAIL_UI_SHOP_H
#include "Shop.h"
#include "TexasTrail.h"
#include "DialoguePrompt.h"
#include "TablePrompt.h"
#include "Utils.h"
#include "IntPrompt.h"
#include "UI.h"

class UI;
class UIShop {
    public:
        enum class Return {
            CONTINUE,
            SAVE_AND_EXIT
        };

    public:
        using StringList = std::vector<std::string>;
        using AddRet = Inventory::AddRet;

    public: 
        UIShop(TexasTrail& game, Shop& shop, const UI& ui);
        virtual ~UIShop();

        void virtual run();
        void virtual setUIPickItem();
        void virtual setUIPickCount(int index, AddRet prevRet);

    private:
        TexasTrail& _game;
        Shop& _shop;
        const UI& _ui;
};

#endif