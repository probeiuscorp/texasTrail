#include "UIShop.h"

UIShop::UIShop(TexasTrail& game, Shop& shop, UI& ui) : _game(game), _shop(shop), _ui(ui) {

};
UIShop::~UIShop() {};

void UIShop::run() {
    setUIPickItem();
}

void UIShop::setUIPickItem() {
    _ui.clean();
    
    TablePrompt prompt(string("Welcome to "+_shop.name()+"! What would you like to purchase? (Enter '0' to leave)"), StringList({"Name","Quantity","Price"}));
    for(int i=0;i<_shop.stockSize();i++) {
        Shop::Stock& stock = _shop.stockAtIndex(i);
        prompt.add(StringList({string(std::to_string(i+1)+". "+stock.getStack().formatted()), 
                               std::to_string(stock.getCount()), 
                               string(Utils::formatAsCurrency(stock.getPrice()))}));
    }
    int choice = prompt.execute();

    if(choice != 0) {
        setUIPickCount(choice-1, Shop::EnumShopRet::SUCCESS);
    }
}

void UIShop::setUIPickCount(int index, Shop::EnumShopRet prevRet) {
    _ui.clean();
    Shop::Stock& stock = _shop.stockAtIndex(index);
    if(prevRet != Shop::EnumShopRet::SUCCESS) {
        string error;
        switch(prevRet) {
            case Shop::EnumShopRet::NOT_ENOUGH_SPACE:
                error = "Not enough space";
            case Shop::EnumShopRet::NOT_ENOUGH_MONEY:
                error = "Not enough money";
        }
        Log::log("%sThat did not work." __RESET " (%s)\n", Style::New(Formatting::Color::RED).with(Formatting::Format::BOLD).text().c_str(), error.c_str());
    }
    IntPrompt prompt(string("How many \""+stock.getStack().item().name()+ "\" would you like to purchase? (0-"+std::to_string(stock.getCount())+")"), 0, stock.getCount());
    int count = prompt.execute();
    if(count != 0) {
        Shop::EnumShopRet ret = _shop.purchaseStock(index, count, _game.party());
        if(ret != Shop::EnumShopRet::SUCCESS) {
            setUIPickCount(index, ret);
        }
    }
    setUIPickItem();
}