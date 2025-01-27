#include "Enums.h"

namespace Enums {
    double paceToSpeed(Pace pace) {
        switch(pace) {
            case Pace::FAST:
                return 1.6;
            case Pace::NORMAL:
                return 1.3;
            case Pace::SLOW:
            default:
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
            default:
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
            default:
                return string("Minimal");
        }
    }

    string toString(Biome::BiomeEnum biome) {
        switch(biome) {
            case Biome::BiomeEnum::FOREST :
                return string("Forest");
            case Biome::BiomeEnum::MOUNTAINS:
            default:
                return string("Mountains");
        }
    }

    string toString(Person::Gender gender) {
        switch(gender) {
            case Person::Gender::FEMALE:
                return string("Female");
            case Person::Gender::MALE:
            default:
                return string("Male");
        }
    }
}