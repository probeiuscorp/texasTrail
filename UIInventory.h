#ifndef TEXAS_TRAIL_UI_INVENTORY
#define TEXAS_TRAIL_UI_INVENTORY
#include <string>
#include <vector>
#include "UI.h"
#include "inventory/Inventory.h"
using std::string;
using std::vector;

class UIInventory {
    public:
        UIInventory(Inventory& inventory, const UI& ui);
        virtual ~UIInventory();

        virtual void run();
        virtual void setUIListItems();
        virtual void setUIItemAction(int index);

    private:
        Inventory& _inventory;
        const UI& _ui;
};

#endif