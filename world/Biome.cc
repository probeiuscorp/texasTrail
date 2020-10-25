#include "Biome.h"

Biome::Biome(Biome::BiomeEnum biome) {
    switch(biome) {
        case BiomeEnum::FOREST:
            _temperature = 80;
            break;
        case BiomeEnum::MOUNTAINS:
            _temperature = 65;
    }
}