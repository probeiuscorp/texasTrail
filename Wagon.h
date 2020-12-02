#ifndef TEXAS_TRAIL_WAGON_H
#define TEXAS_TRAIL_WAGON_H
#include "inventory/Inventory.h"

class Wagon {
    public:
        Wagon(int maxWeight) {}
        virtual ~Wagon() {}

    private:
        Inventory _inventory;
};

#endif