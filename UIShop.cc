#include "UIShop.h"

UIShop::UIShop(TexasTrail& game, Shop& shop, const UI& ui) : _game(game), _shop(shop), _ui(ui) {

};
UIShop::~UIShop() {};

void UIShop::run() {
    setUIPickItem();
}

void UIShop::setUIPickItem() {
    _ui.clean();
    
    TablePrompt prompt(string("Welcome to "+_shop.name()+"! What would you like to purchase? (Enter '0' to leave)"), StringList({"Name","Quantity","Price"}));
    for(int i=0;i<_shop.stockSize();i++) {
        const Shop::Stock& stock = _shop.stockAtIndex(i);
        prompt.add(StringList({string(std::to_string(i+1)+". "+std::to_string(stock.getStack().count())+"x "+stock.getStack().item().name()), 
                               std::to_string(stock.getCount()), 
                               string(Utils::formatAsCurrency(stock.getPrice()))}));
    }
    int choice = prompt.execute();

    if(choice != 0) {
        setUIPickCount(_shop.stockAtIndex(choice-1));
    }
}

void UIShop::setUIPickCount(Shop::Stock stock) {
    _ui.clean();

    IntPrompt prompt(string("How many \""+stock.getStack().item().name()+ "\" would you like to purchase? (0-"+std::to_string(stock.getCount())+")"), 0, stock.getCount());
    prompt.execute();
    setUIPickItem();
}