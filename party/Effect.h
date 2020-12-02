#ifndef TEXAS_TRAIL_EFFECT_H
#define TEXAS_TRAIL_EFFECT_H
#include <string>
using std::string;

class Person;
class Effect {
    protected:
        Effect() {}

    public:
        virtual ~Effect() {}

        // returns true if the effect expired
        virtual bool tick(Person* person, int hours) = 0;
        virtual string display() = 0;
};

#endif