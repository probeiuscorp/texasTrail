#include "Party.h"

Party::Party() {
    _members.resize(_partySize);

}
Party::~Party() {

}

Person& Party::getPartyMember(int index) {
    if(0 < index || index > _partySize) {
        return _members[index];
    }

    // THROW ERROR?
    return _members[index];
}

int Party::getPartySize() const {
    return _partySize;
}