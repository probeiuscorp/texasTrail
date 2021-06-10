#include "Person.h"
#include "EffectBrokenLeg.h" // temporary
#include "EventDeath.h"

Person::Person(string name, Gender gender) : _name(name), _gender(gender) {};
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

Person::EventList Person::tick(int hours) {
    EffectList el;
    for(Effect* effect : _effects) {
        if(!effect->tick(hours)) {
            el.push_back(effect);
        }
    }
    _effects.swap(el);

    EventList _events;
    if(!_dead) {
        if(rand()%90<hours) {
            setHealth(-0.5);
        }

        if(_health > 100) _health = 100;
        if(_energy > 100) _energy = 100;
        if(_energy < 0) _energy = 0;
        if(_health <= 0) {
            kill();
            _events.push_back(new EventDeath(this));
        }
    }
    return _events;
}

void Person::kill() {
    _dead = true;
    for(Effect* effect : _effects) {
        delete effect;
    }
    _effects.clear();
}