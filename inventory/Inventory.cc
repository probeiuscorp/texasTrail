#include "Inventory.h"

Inventory::Inventory() : _stacks(StackList()) {}
Inventory::Inventory(StackList stacks) : _stacks(stacks) {}
Inventory::~Inventory() {
    for(Stack* stack : _stacks) {
        delete stack;
    }
}

Inventory::AddRet Inventory::add(Stack& stack) {
    return add(&stack);
}

Inventory::AddRet Inventory::add(Stack* stack) {
    if(_hasMax) {
        updateWeight();
        if(_currentWeight > _maxWeight) {
            return AddRet::NO_SPACE;
        }
    }
    bool uniqueItem = true;
    for(int i=0;i<_stacks.size();i++) {
        if(&(_stacks[i]->item()) == &(stack->item())) {
            uniqueItem = false;
            _stacks[i]->setCount(_stacks[i]->count()+stack->count());
            break;
        }
    }
    if(uniqueItem) {
        _stacks.push_back(stack);
    }
    return AddRet::SUCCESS;
}

void Inventory::remove(int index) {
    auto it = _stacks.begin() + index;
    _stacks.erase(it);
}

void Inventory::updateWeight() {
    _currentWeight = 0;
    for(const Stack* stack : _stacks) {
        _currentWeight += stack->weight();
    }
}