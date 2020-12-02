#include "Person.h"
#include "party/EffectBrokenLeg.h"

Person::Person() {};
Person::Person(string name) : _name(name) {
    
};
Person::~Person() {
    for(Effect* effect : _effects) {
        delete effect;
    }
};

void Person::setName(string name) {
    _name = name;
}
std::string Person::name() const {
    return _name;
}

void Person::tick(int hours) {
    EffectList el;
    for(Effect* effect : _effects) {
        if(!effect->tick(this, hours)) {
            el.push_back(effect);
        }
    }
    _effects.swap(el);
}

void Person::cb() {
    if(_health > 100) {
        _health = 100;
    } else if(_health <= 0) {
        kill();
    }
    if(_energy > 100) {
        _energy = 100;
    } else if(_energy < 0) {
        _energy = 0;
    }
}

void Person::kill() {}