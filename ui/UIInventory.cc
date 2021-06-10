#include "ui/UIInventory.h"

UIInventory::UIInventory(Inventory& inventory, UI& ui) : _inventory(inventory), _ui(ui) {}
UIInventory::~UIInventory() {}

void UIInventory::run() {
    setUIListItems();   
}

void UIInventory::setUIListItems() {
    while(true) {
        _ui.clean();
        TablePrompt prompt("Please select an item in the inventory: (0 to leave)", StringList({"Item", "Count", "Weight"}));
        int i=0;
        for(Stack* stack : _inventory.stacks()) {
            prompt.add(StringList({string(std::to_string(i+1)+". "+stack->item().name()), std::to_string(stack->count()), Utils::formatAsWeight(stack->weight())}));
            i++;
        }

        int choice = prompt.execute();

        if(choice == 0) {
            break;
        } else {
            setUIItemAction(choice-1);
        }
    }
}

void UIInventory::setUIItemAction(int index) {
    _ui.clean();
    DialoguePrompt prompt(string("What would you like to do with "+_inventory.get(index).formatted()), StringList({"Cancel","Remove from inventory"}));
    switch(prompt.execute()) {
        case 2:
            setUIRemove(index);
            break;
    }
}

void UIInventory::setUIRemove(int index) {
    _ui.clean();
    IntPrompt prompt(string("How many would you like to remove? (0-"+std::to_string(_inventory.get(index).count())+")"), 0, _inventory.get(index).count());
    int amount = prompt.execute();
    if(_inventory.get(index).count() == amount) {
        _inventory.remove(index);
    } else {
        _inventory.get(index).setCount(_inventory.get(index).count()-amount);
    }
}