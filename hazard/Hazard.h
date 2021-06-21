#ifndef TEXAS_TRAIL_HAZARD_H
#define TEXAS_TRAIL_HAZARD_H
#include "Hazards.h"
#include <list>
#include <string>
using std::list;
using std::string;

class TexasTrail;
class Wagon;
class WagonHazard {
    public:
        WagonHazard() {}
        virtual ~WagonHazard() {}

        virtual void tryToApply(Wagon* wagon, TexasTrail* game, int hours) = 0;
};

class Person;
class PersonHazard {
    public:
        PersonHazard() {}
        virtual ~PersonHazard() {}

        virtual void tryToApply(Person* person, TexasTrail* game, int hours) = 0;
};

class Party;
class PartyHazard {
    public:
        PartyHazard() {}
        virtual ~PartyHazard() {}

        virtual void tryToApply(Party* party, TexasTrail* game, int hours) = 0;
};

#endif