#include "UIInventory.h"

UIInventory::UIInventory(Inventory& inventory, const UI& ui) : _inventory(inventory), _ui(ui) {}
UIInventory::~UIInventory() {}

void UIInventory::run() {
    setUIListItems();   
}

void UIInventory::setUIListItems() {
    TablePrompt prompt("Please select an item in the inventory: (0 to leave)", StringList({"Item", "Count", "Weight"}));
    for(const Stack* stack : _inventory.stacks()) {
        prompt.add(StringList({stack->item().name(), stack->formatted(), Utils::formatAsWeight(stack->weight())}));
    }

    int choice = prompt.execute();

    if(choice != 0) {
        setUIItemAction(choice-1);
    }
}

void UIInventory::setUIItemAction(int index) {
    DialoguePrompt prompt(string("What would you like to do with "+_inventory.get(index).formatted()), StringList({"Remove from inventory"}));
    switch(prompt.execute()) {
        case 1:
            _inventory.remove(index);
            break;
    }
}