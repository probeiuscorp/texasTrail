#ifndef TEXAS_TRAIL_EFFECT_DISEASE_H
#define TEXAS_TRAIL_EFFECT_DISEASE_H
#include "Effect.h"

class Person;
class EffectDisease : public Effect {
    public:
        EffectDisease(double damage, double curability, string name, string display);
        bool tick(Person* person, int hours) override;
        virtual string display(Person* person) override { return _display; };
        virtual string name() { return _name; }
        virtual double curability() { return _curability; }

    private:
        double _damage;
        double _curability;
        string _name;
        string _display;
};

#endif