#ifndef TEXAS_TRAIL_EFFECT_BROKEN_LEG_H
#define TEXAS_TRAIL_EFFECT_BROKEN_LEG_H
#include "party/Effect.h"

class EffectBrokenLeg : public Effect {
    public:
        EffectBrokenLeg();
        virtual ~EffectBrokenLeg() {}

        virtual bool tick(Person* person, int hours) override;
        virtual string display() override;
};

#endif