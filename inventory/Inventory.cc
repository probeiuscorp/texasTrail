#include "Inventory.h"

Inventory::Inventory() : _stacks(StackList()) {}
Inventory::Inventory(StackList stacks) : _stacks(stacks) {}
Inventory::~Inventory() {
    for(Stack* stack : _stacks) {
        delete stack;
    }
}

bool Inventory::add(Stack& stack) {
    if(_hasMax) {
        updateWeight();
        if(_currentWeight > _maxWeight) {
            return false;
        }
    }
    _stacks.push_back(&stack);
    return true;
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