#ifndef TEXAS_TRAIL_INVENTORY_H
#define TEXAS_TRAIL_INVENTORY_H
#include "Stack.h"
#include <vector>
using std::vector;

class Inventory {
    public:
        // Switch-cases that need updating when new types added: 
        // UIShop::setUIPickCount()
        enum class AddRet {
            SUCCESS,
            NO_SPACE
        };

    public:
        using StackList = vector<Stack*>;

    public:
        Inventory();
        Inventory(StackList stacks);
        virtual ~Inventory();

        // Returns true if successful, false otherwise
        virtual AddRet add(Stack& stack);
        virtual AddRet add(Stack* stack);
        virtual Stack& get(int index) { return *(_stacks[index]); }
        virtual void remove(int index);
        virtual int size() { return _stacks.size(); }
        virtual StackList& stacks() { return _stacks; }

        virtual void setHasMax(bool hasMax) { _hasMax = hasMax; }
        virtual void setMaxWeight(int maxWeight) { _maxWeight = maxWeight; }

    private:
        StackList _stacks;
        int _maxWeight = 0;
        bool _hasMax = false;
        int _currentWeight = 0;

    private:
        virtual void updateWeight();
};

#endif