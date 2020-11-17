#ifndef TEXAS_TRAIL_ENUMS_H
#define TEXAS_TRAIL_ENUMS_H
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
};

#endif