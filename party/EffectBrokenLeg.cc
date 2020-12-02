#include "EffectBrokenLeg.h"
#include "Person.h"

EffectBrokenLeg::EffectBrokenLeg() : Effect() {

}

bool EffectBrokenLeg::tick(Person* person, int hours) {
    person->modifyHealth(-0.8*hours);
    return false;
}

string EffectBrokenLeg::display() {
    return "Broken leg. Party speed reduced to 25%.";
}