#ifndef TEXAS_TRAIL_PERSON_H
#define TEXAS_TRAIL_PERSON_H
#include "Effect.h"
#include "Event.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Person {
    public:
        enum class Gender {
            FEMALE,
            MALE
        };

    public:
        using EffectList = vector<Effect*>;
        using EventList = vector<Event*>;

    public:
        Person(string name, Gender gender);
        ~Person();

        void setName(string name);
        string name() const;
        void setHealth(double health) { _health = health; }
        double health() const { return _health; }
        void modifyHealth(double healthM) { _health += healthM; }
        void setEnergy(double energy) { _energy = energy; }
        double energy() const { return _energy; }
        void modifyEnergy(double energyM) { _energy += energyM; }
        EffectList effects() const { return _effects; }
        bool isDead() const { return _dead; }
        Gender gender() const { return _gender; }

        EventList tick(int hours);
        void kill();

    private:
        string _name;
        double _health = 100;
        double _energy = 100;
        bool _dead = false;
        EffectList _effects;
        Gender _gender;
};

#endif