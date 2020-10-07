#ifndef TEXAS_TRAIL_PARTY_H
#define TEXAS_TRAIL_PARTY_H
#include "Person.h"
#include <vector>

class Party {
    public:
        Party();
        ~Party();

        Person& getPartyMember(int index);
        int getPartySize() const;
    
    private:
        std::vector<Person> _members;
        int _partySize;
};

#endif