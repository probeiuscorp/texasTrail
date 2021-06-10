#ifndef TEXAS_TRAIL_EFFECT_H
#define TEXAS_TRAIL_EFFECT_H
#include <string>
using std::string;

class Person;
class Effect {
    protected:
        Effect(Person* person) { _person = person; }

    public:
        virtual ~Effect() {}

        // Should return true if the effect expired.
        virtual bool tick(int hours) = 0;
        virtual string display() = 0;

    protected:
        Person* _person;
};

#endif