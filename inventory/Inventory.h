#ifndef TEXAS_TRAIL_INVENTORY_H
#define TEXAS_TRAIL_INVENTORY_H
#include "Stack.h"
#include <vector>
using std::vector;

class Inventory {
    public:
        using StackList = vector<Stack*>;

    public:
        Inventory();
        Inventory(StackList stacks);
        Inventory(double maxWeight);
        Inventory(double maxWeight, StackList stacks);
        virtual ~Inventory();

        // Returns true if there was not enough space
        virtual bool add(Stack& stack);
        virtual bool add(Stack* stack);
        virtual Stack& get(int index) { return *(_stacks[index]); }
        virtual void remove(int index);
        virtual int size() { return _stacks.size(); }
        virtual StackList& stacks() { return _stacks; }

        virtual void setHasMax(bool hasMax) { _hasMax = hasMax; }
        virtual void setMaxWeight(double maxWeight) { _maxWeight = maxWeight; }

    protected:
        StackList _stacks;
        double _maxWeight = 0;
        bool _hasMax = false;
        double _currentWeight = 0;

    protected:
        virtual void updateWeight();
};

#endif