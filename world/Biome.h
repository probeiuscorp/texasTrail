#ifndef TEXAS_TRAIL_BIOME_H
#define TEXAS_TRAIL_BIOME_H

class Biome {
    public:
        enum class BiomeEnum {
            MOUNTAINS,
            FOREST
        };

    public:
        Biome(BiomeEnum biome);
        virtual ~Biome() {}

        virtual BiomeEnum enumType() const { return _biome; }
        virtual int temperature() const { return _temperature; }
    private:
        int _temperature;
        BiomeEnum _biome;
};

#endif