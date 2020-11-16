#include "Enums.h"

namespace Enums {
    double paceToSpeed(Pace pace) {
        switch(pace) {
            case Pace::FAST:
                return 1.5;
            case Pace::NORMAL:
                return 1.0;
            case Pace::SLOW:
                return 0.5;
        }
    }
}