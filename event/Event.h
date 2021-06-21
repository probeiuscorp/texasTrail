#ifndef TEXAS_TRAIL_EVENT_H
#define TEXAS_TRAIL_EVENT_H
#include "DialoguePrompt.h"
#include "Colors.h"
#include "Utils.h"

class Person;
class Party;
class Wagon;
class Event {
    public:
        using StringList = DialoguePrompt::StringList;

    protected:
        Event(Person* person) { _person = person; }
        Event(Party* party) { _party = party; }
        Event(Wagon* wagon) { _wagon = wagon; }
        Event() {}

    public:
        virtual ~Event() {}

        virtual string popup() { return _popup; }
        virtual void callback() {};

    protected:
        string _popup;
        Person* _person = nullptr;
        Party* _party = nullptr;
        Wagon* _wagon = nullptr;
};

#endif