#ifndef TEXAS_TRAIL_WAGON_FIRE_H
#define TEXAS_TRAIL_WAGON_FIRE_H
#include "Hazard.h"
#include "Event.h"

class Wagon;
class TexasTrail;
class HazardWagonFire : public WagonHazard {
    public:
        virtual void tryToApply(Wagon* subject, TexasTrail* game, int hours) override;
};

#endif