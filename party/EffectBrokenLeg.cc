#include "EffectBrokenLeg.h"
#include "Person.h"

EffectBrokenLeg::EffectBrokenLeg(Person* person) : Effect(person) {}

bool EffectBrokenLeg::tick(int hours) {
    // person->modifyHealth(-0.8*hours);
    _person->kill();
    return false;
}

string EffectBrokenLeg::display() {
    return "Broken leg. Party speed reduced to 25% unless put in wagon.";
}