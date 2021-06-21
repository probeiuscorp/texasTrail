#ifndef TEXAS_TRAIL_EVENT_GENERIC_H
#define TEXAS_TRAIL_EVENT_GENERIC_H
#include "Event.h"

class Person;
class EventGeneric : public Event {
    public:
        EventGeneric(string popup);
        virtual void callback() override;
};

#endif