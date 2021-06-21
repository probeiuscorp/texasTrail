#include "EventGeneric.h"
#include "Utils.h"
#include <iostream>

EventGeneric::EventGeneric(string popup) : Event() {
    _popup = popup;
}

void EventGeneric::callback() {
    Utils::awaitEnterKey();
}