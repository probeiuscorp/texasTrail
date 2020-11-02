#ifndef TEXAS_TRAIL_STACK_H
#define TEXAS_TRAIL_STACK_H
#include "Item.h"
#include <string>
using std::string;

class Stack {
    public:
        Stack(const Item& item);
        Stack(const Item& item, int count);
        Stack(const Stack& source);
        virtual ~Stack();

        virtual const Item& item() const { return _item; };
        virtual int count() const { return _count; };
        virtual double weight() const { return _item.weight()*_count; }
        virtual string formatted() const;

    private:
        const Item& _item;
        int _count;
};

#endif