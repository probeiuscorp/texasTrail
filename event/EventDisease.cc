#include "EventDisease.h"
#include "Person.h"

EventDisease::EventDisease(Person* person, string name) : Event(person) {
    _popup = person->name() + " caught " + name + ".";
}

void EventDisease::callback() {
    DialoguePrompt prompt = DialoguePrompt("What would you like to do?", StringList({"Keep on walking", "Put them in the wagon", "Abandon them"}));
    switch(prompt.execute()) {
        case 1:
        case 2:
        case 3:
            break;
    }
}