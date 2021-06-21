#ifndef TEXAS_TRAIL_UI_USE_ITEM_H
#define TEXAS_TRAIL_UI_USE_ITEM_H
#include "UI.h"
#include "TexasTrail.h"

class UIUseItem {
    public:
        UIUseItem(TexasTrail& game, Party& party, UI& ui) : _ui(ui), _game(game), _party(party) {}
        virtual ~UIUseItem() {}

        virtual void run();
        virtual void setUIPartyMember();
        virtual void setUIWagon();

    private:
        UI& _ui;
        TexasTrail& _game;
        Party& _party;
};

#endif