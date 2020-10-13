#ifndef TEXAS_TRAIL_STACK_H
#define TEXAS_TRAIL_STACK_H
#include "Item.h"

class Stack {
    public:
        Stack();
        Stack(Item item);
        Stack(Item item, int count);
        Stack(const Stack& source);
        virtual ~Stack();

        Item item() const { return _item; };
        int count() const { return _count; };

    private:
        Item _item;
        int _count;
};

#endif