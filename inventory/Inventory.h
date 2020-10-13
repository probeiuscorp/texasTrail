#ifndef TEXAS_TRAIL_INVENTORY_H
#define TEXAS_TRAIL_INVENTORY_H
#include "Item.h"
#include <list>
using std::list;

class Inventory {
    public:
        using ItemList = list<Item>;

    public:
        Inventory();
        virtual ~Inventory();

    private:
        ItemList _items;
};

#endif