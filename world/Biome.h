#ifndef TEXAS_TRAIL_BIOME_H
#define TEXAS_TRAIL_BIOME_H
#include "Color.h"
#include <string>
using std::string;

class Biome {
    public:
        enum class BiomeEnum {
            MOUNTAINS,
            PRAIRIE,
            FOREST
        };

    public:
        Biome(BiomeEnum biome);
        virtual ~Biome() {}

        virtual BiomeEnum enumType() const { return _biome; }
        virtual int temperature() const { return _temperature; }
        virtual const Color& color() const { return _color; }
        virtual string name() const { return _name; }

    private:
        int _temperature;
        BiomeEnum _biome;
        Color _color;
        string _name;
};

#endif