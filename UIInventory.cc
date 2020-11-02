#include "UIInventory.h"

UIInventory::UIInventory(Inventory& inventory, const UI& ui) : _inventory(inventory), _ui(ui) {}
UIInventory::~UIInventory() {}

void UIInventory::run() {
    setUIListItems();   
}

void UIInventory::setUIListItems() {
    TablePrompt prompt("Please select an item in your party's inventory: (0 to leave)", StringList({"Item", "Count", "Weight"}));
    for(const Stack* stack : _inventory.stacks()) {
        prompt.add(StringList({stack->item().name(), stack->formatted(), Utils::formatAsWeight(stack->weight())}));
    }

    int choice = prompt.execute();

    if(choice != 0) {
        
    }
}