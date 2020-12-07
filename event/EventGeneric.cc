#include "event/EventGeneric.h"

// EventGeneric::EventGeneric() {}
// EventGeneric::~EventGeneric() {}

Event::StringList& EventGeneric::popup() {
    return _popup;
}
DialoguePrompt* EventGeneric::prompt() {
    _prompt = new DialoguePrompt("What would you like to do with Bob?", StringList({"Put him in the wagon", "Keep on walking", "Abandon him"}));
    return _prompt;
}
void EventGeneric::callback(int ret) {
    delete _prompt;
    switch(ret) {
        case 3:
            printf("hahaha\n");
        default:
            printf("%d\n", ret);
    }
}