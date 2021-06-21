#include "EventDeath.h"
#include "Person.h"

EventDeath::EventDeath(Person* person) : Event(person) {
    _popup = person->name() + " died.";
}

void EventDeath::callback() {
    DialoguePrompt prompt = DialoguePrompt(string("What would you like to with " + _person->name() + "'s body?"), StringList({
        "Keep on walking",
        "Abandon them",
        "Bury them (costs time and energy)"
    }));
    switch(prompt.execute()) {
        case 2:
            break;
        case 3:
            break;
    }
}