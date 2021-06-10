#ifndef TEXAS_TRAIL_EVENT_DEATH_H
#define TEXAS_TRAIL_EVENT_DEATH_H
#include "Event.h"

class Person;
class EventDeath : public Event {
    public:
        EventDeath(Person* person);
        virtual ~EventDeath() {};

        virtual void callback(int ret) override;
};

#endif