#include "Enums.h"

namespace Enums {
    double paceToSpeed(Pace pace) {
        switch(pace) {
            case Pace::FAST:
                return 1.6;
            case Pace::NORMAL:
                return 1.3;
            case Pace::SLOW:
                return 0.9;
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

    string toString(Biome::BiomeEnum biome) {
        switch(biome) {
            case Biome::BiomeEnum::FOREST :
                return string("Forest");
            case Biome::BiomeEnum::MOUNTAINS:
                return string("Mountains");
        }
    }
}