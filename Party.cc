#include "Party.h"

Party::Party(StringList names, World& world) : _world(world) {
    _partySize = names.size();
    _members.resize(_partySize);
    for(int i=0;i<_partySize;i++) {
        _members[i].setName(names[i]);
    }
}
Party::~Party() {

}

Person& Party::getPartyMember(int index) {
    if(0 < index || index > _partySize) {
        return _members[index];
    } else {
        printf("Index out of bounds. Index: %d, Size: %d\n", index, _partySize);
        abort();
    }
}

int Party::getPartySize() const {
    return _partySize;
}

void Party::tick(int hours) {
    _distance += Enums::paceToSpeed(_pace) * hours;
}