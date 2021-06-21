#ifndef TEXAS_TRAIL_ITEM_MEDICINE_H
#define TEXAS_TRAIL_ITEM_MEDICINE_H
#include "Item.h"

class ItemMedicine : public Item {
    public:
        ItemMedicine(string name, double weight) : Item(name, weight) {}
        virtual ~ItemMedicine() {}

        virtual bool canBeUsedOnPerson() const override { return true; }
        virtual bool usableOnPerson(Person* person) const override;
        virtual string useOnPerson(Person* person) const override;
};

#endif