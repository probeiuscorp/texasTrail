#ifndef TEXAS_TRAIL_EVENT_H
#define TEXAS_TRAIL_EVENT_H
#include "DialoguePrompt.h"

class Person;
class Event {
    public:
        using StringList = DialoguePrompt::StringList;

    protected:
        Event(Person* person) { _person = person; }

    public:
        virtual ~Event();

        virtual StringList* popup() const { return _popup; }
        virtual DialoguePrompt* prompt() const { return _prompt; };
        virtual void callback(int ret) = 0;

    protected:
        StringList* _popup;
        DialoguePrompt* _prompt;
        Person* _person;
};

#endif