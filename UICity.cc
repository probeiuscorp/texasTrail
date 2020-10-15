#include "UICity.h"

UICity::UICity(TexasTrail& game, City& city, const UI& ui) : _game(game), _city(city), _ui(ui) {

}

UICity::~UICity() {}

void UICity::run() {
    /* 
    Continue on trail
    Shop
    View Atlas
    Save & exit
    View inventory
    View party
    */
    setUIHome();
}

void UICity::setUIHome() {
    _ui.clean();

    DialoguePrompt prompt(string("Welcome to "+_city.name()+"! What would you like to do?"), StringList({"Continue on trail","Shop","View Atlas", "View inventory", "View party", "Save & exit"}));
    switch(prompt.execute()) {
        case 1:
            break;
        case 2:
            setUIChooseShop();
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

void UICity::setUIChooseShop() {
    _ui.clean();

    StringList sList({"Leave"});
    
    for(const Shop& shop : _city.shops()) {
        sList.push_back(shop.name());
    }

    DialoguePrompt prompt(string("Where would you like to shop?"), sList);
    int choice = prompt.execute();

    if(choice == 1) {
        setUIHome();
    } else {
        UIShop uiShop(_game, _city.getShop(choice-2), _ui);
        uiShop.run();
    }
}