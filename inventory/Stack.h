#ifndef TEXAS_TRAIL_STACK_H
#define TEXAS_TRAIL_STACK_H
#include "Item.h"

class Stack {
    public:
        Stack(const Item& item);
        Stack(const Item& item, int count);
        Stack(const Stack& source);
        virtual ~Stack();

        const Item& item() const { return _item; };
        int count() const { return _count; };

    private:
        const Item& _item;
        int _count;
};

#endif