#ifndef TEXAS_TRAIL_IMMUNITY_H
#define TEXAS_TRAIL_IMMUNITY_H
#include "EffectDisease.h"
#include <vector>
using std::vector;

class Immunity {
    public:
        Immunity() {}
        virtual ~Immunity() {}

        virtual void add(EffectDisease* disease) { _diseases.push_back(disease); }
        virtual bool has(EffectDisease* disease);
        virtual vector<EffectDisease*> all() { return _diseases; }

    private:
        vector<EffectDisease*> _diseases;
};

#endif