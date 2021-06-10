#include "Biome.h"

Biome::Biome(Biome::BiomeEnum biome) : _biome(biome), _color(0, 0, 0) {
    switch(biome) {
        case BiomeEnum::FOREST:
            _temperature = 80;
            _color = Color(107, 171, 124);
            _name = "Forest";
            break;
        case BiomeEnum::PRAIRIE:
            _temperature = 80;
            _color = Color(107, 171, 124);
            _name = "Prairie";
            break;
        case BiomeEnum::MOUNTAINS:
            _temperature = 65;
            _color = Color(97, 103, 107);
            _name = "Mountains";
            break;
    }
}