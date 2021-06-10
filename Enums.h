#ifndef TEXAS_TRAIL_ENUMS_H
#define TEXAS_TRAIL_ENUMS_H
#include "world/Biome.h"
#include "Person.h"
#include <string>
using std::string;

namespace Enums {
    enum class Pace {
        FAST,
        NORMAL,
        SLOW
    };
    enum class Ration {
        FILLING,
        NORMAL,
        MINIMAL
    };

    extern double paceToSpeed(Pace pace);
    extern string toString(Pace pace);
    extern string toString(Ration ration);
    extern string toString(Biome::BiomeEnum biome);
    extern string toString(Person::Gender gender);
};

#endif