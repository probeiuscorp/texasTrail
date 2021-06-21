#ifndef TEXAS_TRAIL_EVENT_DISEASE_H
#define TEXAS_TRAIL_EVENT_DISEASE_H
#include "Event.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class EventDisease : public Event {
    public:
        using StringList = vector<string>;

    public:
        EventDisease(Person* person, string name);
        virtual void callback() override;

    private:
        string _name;
};

#endif