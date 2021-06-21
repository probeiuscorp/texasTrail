#ifndef TEXAS_TRAIL_ITEMS_H
#define TEXAS_TRAIL_ITEMS_H
#include "inventory/Item.h"
#include "inventory/ItemFood.h"
#include "ItemMedicine.h"

class Items {
    public:
        static const Item AXLE;
        static const Item EGG;
        static const Item MUSKET;
        static const ItemFood MEAT;
        static const ItemFood BREAD;
        static const ItemFood FRUIT;
        static const ItemFood CIGAR;
        static const ItemMedicine MEDICINE;
};

#endif