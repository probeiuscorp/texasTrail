#include "ui/UICity.h"
#include "ui/UIViewParty.h"
#include "UIUseItem.h"

UICity::UICity(TexasTrail& game, City& city, UI& ui) : _game(game), _city(city), _ui(ui) {

}

UICity::~UICity() {}

Path* UICity::run() {
    if(setUIHome()) { 
        return nullptr; 
    }
    
    Path* path = setUIChooseNextPath();
    if(path == nullptr) {
        return run();
    } else {
        return path;
    }
}

bool UICity::setUIHome() {
    _ui.clean();

    DialoguePrompt prompt(string("Welcome to "+_city.name()+"! What would you like to do? ["+Utils::formatAsCurrency(_game.party().money())+"]"), 
        StringList({"Continue on trail","Shop","View Atlas", "View inventory", "Use item", "View party", "Save & exit"}));
    switch(prompt.execute()) {
        case 1:
            break;
        case 2:
            setUIChooseShop();
            break;
        case 3:
            break;
        case 4: {
            UIInventory uiInventory(_game.party().wagon(), _ui);
            uiInventory.run();
            setUIHome();
            break;
        }
        case 5: {
            UIUseItem uiUseItem(_game, _game.party(), _ui);
            uiUseItem.run();
            break;
        }
        case 6: {
            UIViewParty uiViewParty(_game.party(), _ui);
            uiViewParty.run();
            break;
        }
        case 7:
            return true;
            break;
    }
    return false;
}

void UICity::setUIChooseShop() {
    _ui.clean();

    StringList sList({"Leave"});
    
    for(int i=0;i<_city.shopSize();i++) {
        sList.push_back(_city.getShop(i).name());
    }

    DialoguePrompt prompt(string("Where would you like to shop?"), sList);
    int choice = prompt.execute();

    if(choice != 1) {
        UIShop uiShop(_game, _city.getShop(choice-2), _ui);
        uiShop.run();
    }
    setUIHome();
}

Path* UICity::setUIChooseNextPath() {
    _ui.clean();
    return UICommons::nextPathSelector(_game.party().node()->paths()); 
}