#include "Person.h"
#include "Hazard.h"
#include "EventDeath.h"

Person::Person(string name, Gender gender) : _name(name), _gender(gender) {};
Person::~Person() {};

void Person::setName(string name) {
    _name = name;
}
std::string Person::name() const {
    return _name;
}

Person::EventList Person::tick(int hours) {
    EffectList el;
    for(Effect* effect : _effects) {
        if(!effect->tick(this, hours)) {
            el.push_back(effect);
        }
    }
    _effects.swap(el);

    if(!_dead) {
        if(_health > 100) _health = 100;
        if(_energy > 100) _energy = 100;
        if(_energy < 0) _energy = 0;
        if(_health <= 0) {
            kill();
            addEvent(new EventDeath(this));
        }
    }

    return _events;
}

bool Person::hasEffect(Effect* effect) const {
    for(Effect* _effect : _effects) {
        if(_effect == effect) return true;
    }
    return false;
}

void Person::removeEffect(Effect* effect) {
    auto it = _effects.begin();
    while(it != _effects.end()) {
        if(*it.base() == effect) {
            _effects.erase(it);
            break;
        }
        it++;
    }
}

void Person::clearEvents() {
    for(Event* event : _events) {
        delete event;
    }
    _events.clear();
}

void Person::kill() {
    _dead = true;
    _effects.clear();
}