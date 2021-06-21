#include "Wagon.h"
#include "Utils.h"
#include "Event.h"

vector<Event*> Wagon::tick(int hours) {
    vector<Event*> events;
    return events;
}

void Wagon::clearEvents() {
    for(Event* event : _events) {
        delete event;
    }
    _events.clear();
}