#include "EffectDisease.h"
#include "Person.h"
#include "Utils.h"
#include "EventDiseaseCured.h"

EffectDisease::EffectDisease(double damage, double curability, string name, string display) : Effect() {
    _damage = damage;
    _curability = curability;
    _name = name;
    _display = display;
}

bool EffectDisease::tick(Person* person, int hours) {
    person->modifyHealth(-((_damage*6)/24.0)*hours);
    for(int i=0;i<hours;i++) {
        if(Utils::chance(_curability/(24*4))) {
            person->addEvent(new EventDiseaseCured(person, _name));
            person->immunity().add(this);
            person->removeEffect(this);
            return true;
        } // Likely to get cured after 4 days
    }
    return false;
}