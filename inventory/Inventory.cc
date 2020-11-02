#include "Inventory.h"

Inventory::Inventory() : _stacks(StackList()) {}
Inventory::Inventory(StackList stacks) : _stacks(stacks) {}
Inventory::~Inventory() {}

bool Inventory::add(Stack* stack) {
    if(_hasMax) {
        updateWeight();
        if(_currentWeight > _maxWeight) {
            return false;
        }
    }
    _stacks.push_back(stack);
    return true;
}

void Inventory::updateWeight() {
    _currentWeight = 0;
    for(const Stack* stack : _stacks) {
        _currentWeight += stack->weight();
    }
}