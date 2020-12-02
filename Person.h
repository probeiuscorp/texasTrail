#ifndef TEXAS_TRAIL_PERSON_H
#define TEXAS_TRAIL_PERSON_H
#include <string>
#include <vector>
#include "party/Effect.h"
using std::string;
using std::vector;

class Person {
    public:
        using EffectList = vector<Effect*>;

    public:
        Person();
        Person(string name);
        ~Person();

        void setName(string name);
        string name() const;
        void setHealth(double health) { _health = health; cb(); }
        double health() const { return _health; }
        void modifyHealth(double healthM) { _health += healthM; cb(); }
        void setEnergy(double energy) { _energy = energy; cb(); }
        double energy() const { return _energy; }
        void modifyEnergy(double energyM) { _energy += energyM; cb(); }
        EffectList effects() const { return _effects; }

        void tick(int hours);
        void kill();

    private:
        void cb();

    private:
        string _name;
        double _health = 100;
        double _energy = 100;
        EffectList _effects;
};

#endif