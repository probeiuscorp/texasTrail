#include "UIShop.h"

UIShop::UIShop(TexasTrail& game, Shop& shop) : _game(game), _shop(shop) {

};
UIShop::~UIShop() {};

void UIShop::run() {
    DialoguePrompt prompt(string("Welcome to "+_shop.name()+"! What would you like to purchase?"), StringList({"Leave",""}));
    switch(prompt.execute()) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
    }
}