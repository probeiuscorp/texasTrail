#include "UIShop.h"

UIShop::UIShop(TexasTrail& game, Shop& shop) : _game(game), _shop(shop) {

};
UIShop::~UIShop() {};

void UIShop::run() {
    TablePrompt prompt(string("Welcome to Ye Olde Shoppe! What would you like to purchase?\n(Enter '0' to leave)"), StringList({"Name","Quantity","Price"}));
    prompt.add(StringList({"1. Food","20","$75"}));
    prompt.add(StringList({"2. Axles","3","$150"}));
    prompt.add(StringList({"3. Clothes","12","$40"}));
    prompt.add(StringList({"4. Cattle","2","$900"}));
    prompt.execute();
}