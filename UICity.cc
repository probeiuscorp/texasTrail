#include "UICity.h"

UICity::UICity(TexasTrail& game, City& city, const UI& ui) : _game(game), _city(city), _ui(ui) {

}

UICity::~UICity() {}

Path* UICity::run() {
    if(setUIHome()) { 
        return nullptr; 
    }
    if(_game.party().node()->paths().size() > 1) {
        Path* path = setUIChooseNextPath();
        if(path == nullptr) {
            run();
        } else {
            return path;
        }
    } else {
        return _game.party().node()->paths()[0];
    }
}

bool UICity::setUIHome() {
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