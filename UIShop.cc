#include "UIShop.h"

UIShop::UIShop(TexasTrail& game, Shop& shop) : _game(game), _shop(shop) {

};
UIShop::~UIShop() {};

void UIShop::run() {
    setUIPickItem();
}

void UIShop::setUIPickItem() {
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
    IntPrompt prompt(string("How many \""+stock.getStack().item().name()+ "\" would you like to purchase? (0-"+std::to_string(stock.getCount())+")"), 0, stock.getCount());
    prompt.execute();
    setUIPickItem();
}