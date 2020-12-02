#include "Party.h"

Party::Party(StringList names, World& world) : _world(world) {
    _partySize = names.size();
    for(int i=0;i<_partySize;i++) {
        _members.push_back(new Person(names[i]));
    }
}
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

void Party::tick(int hours) {
    _distance += Enums::paceToSpeed(_pace) * hours;

    for(Person* person : _members) {
        person->tick(hours);
    }
}