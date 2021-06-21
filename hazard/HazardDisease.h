#ifndef TEXAS_TRAIL_DISEASE_H
#define TEXAS_TRAIL_DISEASE_H
#include "Hazard.h"
#include <list>

class Event;
class EffectDisease;
class Person;
class Party;
class HazardDisease : public PersonHazard {
    public:
        // 1.0 is the normal amount of damage or infectious
        HazardDisease(double infectious, double common, string name, EffectDisease* effect);
        virtual ~HazardDisease() {}

        virtual void tryToApply(Person* person, TexasTrail* game, int hours) override;

    private:
        double _infectious;
        double _common;
        string _name;
        EffectDisease* _effect;
};

#endif