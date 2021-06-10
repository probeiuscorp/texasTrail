#include "Wagon.h"
#include "ICargo.h"

Wagon::Wagon(double capacity) : _capacity(capacity) {}
Wagon::~Wagon() {
    for(ICargo* cargo : _content) {
        delete cargo;
    }
}

bool Wagon::add(ICargo* item) {
    double weight = item->getWeight();
    if(_weight + weight > _capacity) {
        return false;
    } else {
        _content.push_back(item);
        _weight += weight;
        return true;
    }
}

void Wagon::remove(int index) {
    _weight -= _content[index]->getWeight();
    _content.erase(_content.begin() += index);
}

const Wagon::CargoList Wagon::content() const {
    return _content;
}