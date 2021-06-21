#include "Party.h"
#include "PersonGenerator.h"
#include "TexasTrail.h"

Party::Party(vector<Person*> members, World& world) : _members(members), _world(world), _wagon(Wagon(20000.0)) {}
Party::~Party() {
    for(Person* person : _members) {
        delete person;
    }
}

Person& Party::getPartyMember(int index) {
    if(0 <= index || index > _partySize) {
        return *(_members[index]);
    } else {
        printf("Index out of bounds. Index: %d, Size: %d\n", index, _partySize);
        abort();
    }
}

int Party::getPartySize() const {
    return _partySize;
}

bool Party::modifyMoney(double moneyM) {
    if(_money + moneyM >= 0) {
        _money += moneyM;
        return true;
    } else {
        return false;
    }
}

// Should be called after date is advanced
Party::EventList Party::tick(int hours, Date* date) {
    for(int i=0;i<hours;i++) {
        if(_hoursActive[date->hour()-i-1]) {
            _distance += Enums::paceToSpeed(_pace);
        }
    }
    EventList events;
    for(int i=0;i<_members.size();i++) {
        for(Event* event : _members[i]->tick(hours)) {
            events.push_back(event);
        }
    }
    return events;
}

void Party::clearEvents() {
    _wagon.clearEvents();
    for(Person* member : _members) {
        member->clearEvents();
    }
}

void Party::setHours(vector<bool> hours) {
    if(hours.size() != 24) {
        printf("[Party$setHours()] Tried to set the hours of party but it wasn't of size 24\n");
        fflush(stdout);
        abort();
    } else {
        _hoursActive = hours;
    }
}