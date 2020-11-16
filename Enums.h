#ifndef TEXAS_TRAIL_ENUMS_H
#define TEXAS_TRAIL_ENUMS_H

namespace Enums {
    enum class Pace {
        FAST,
        NORMAL,
        SLOW
    };

    extern double paceToSpeed(Pace pace);
};

#endif