#include "EventDeath.h"
#include "Person.h"

EventDeath::EventDeath(Person* person) : Event(person) {
    _popup = new StringList({string(person->name() + " died.")});
    _prompt = new DialoguePrompt(string("What would you like to with " + person->name() + "'s body?"), StringList({
        "Keep on walking",
        "Abandon them",
        "Bury them (costs time and energy)"
    }));
}

void EventDeath::callback(int ret) {
    switch(ret) {
        case 2:
            break;
        case 3:
            break;
    }
}