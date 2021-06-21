#include "HazardDisease.h"
#include "EventDisease.h"
#include "Utils.h"
#include "Person.h"
#include "TexasTrail.h"

HazardDisease::HazardDisease(double infectious, double common, string name, EffectDisease* effect) : PersonHazard() {
    _infectious = infectious;
    _common = common;
    _name = name;
    _effect = effect;
}

void HazardDisease::tryToApply(Person* person, TexasTrail* game, int hours) {
    if(person->hasEffect(_effect)) return;
    
    double chance = _common/(24*30);

    if(person->immunity().has(_effect)) {
        chance *= 0.05;
    }

    for(int i=0;i<game->party().getPartySize();i++) {
        if(game->party().getPartyMember(i).hasEffect(_effect)) {
            chance += (0.1*_infectious)/(24*2);
        }
    }

    for(int i=0;i<hours;i++) {
        if(Utils::chance(chance)) {
            person->addEffect(_effect);
            person->addEvent(new EventDisease(person, _name));
            return;
        }
    }
}