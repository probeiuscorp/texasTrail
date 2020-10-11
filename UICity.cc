#include "UICity.h"

UICity::UICity(TexasTrail& game, City& city) : _game(game), _city(city) {

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
    DialoguePrompt prompt(string("Welcome to "+_city.name()+"! What would you like to do?"), StringList({"Continue on trail","Shop","View Atlas", "View inventory", "View party", "Save & exit"}));
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

    TablePrompt tPrompt(string("Welcome to Ye Olde Shoppe! What would you like to purchase?"), StringList({"Name","Quantity","Price"}));
    tPrompt.add(StringList({"1. Food","20","$75"}));
    tPrompt.add(StringList({"2. Axles","3","$150"}));
    tPrompt.add(StringList({"3. Clothes","12","$40"}));
    tPrompt.add(StringList({"4. Cattle","2","$900"}));
    tPrompt.execute();
}