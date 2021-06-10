#include "Party.h"
#include "PersonGenerator.h"

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

Party::EventList Party::tick(int hours) {
    _distance += Enums::paceToSpeed(_pace) * hours;
    
    EventList events;
    for(Person* person : _members) {
        for(Event* event : person->tick(hours)) {
            events.push_back(event);
        }
    }
    return events;
}