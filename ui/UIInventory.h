#ifndef TEXAS_TRAIL_UI_INVENTORY
#define TEXAS_TRAIL_UI_INVENTORY
#include "ui/UI.h"
#include "inventory/Inventory.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class UI;
class UIInventory {
    public:
        UIInventory(Inventory& inventory, UI& ui);
        virtual ~UIInventory();

        virtual void run();
        virtual void setUIListItems();
        virtual void setUIItemAction(int index);
        virtual void setUIRemove(int index);

    private:
        Inventory& _inventory;
        UI& _ui;
};

#endif