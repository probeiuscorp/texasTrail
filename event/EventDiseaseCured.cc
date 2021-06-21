#include "EventDiseaseCured.h"
#include "Person.h"

EventDiseaseCured::EventDiseaseCured(Person* person, string name) : Event(person) {
    _popup = person->name() + " has been cured of " + name + ".";
}

void EventDiseaseCured::callback() {
    Utils::awaitEnterKey();
    // DialoguePrompt prompt = DialoguePrompt("Continue", StringList({"Yes"}));
    // prompt.execute();
}