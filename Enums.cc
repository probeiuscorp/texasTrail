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

    string toString(Pace pace) {
        switch(pace) {
            case Pace::FAST:
                return string("Fast");
            case Pace::NORMAL:
                return string("Normal");
            case Pace::SLOW:
                return string("Slow");
        }
    }

    string toString(Ration ration) {
        switch(ration) {
            case Ration::FILLING:
                return string("Filling");
            case Ration::NORMAL:
                return string("Normal");
            case Ration::MINIMAL:
                return string("Minimal");
        }
    }
}