#ifndef TEXAS_TRAIL_PARTY_H
#define TEXAS_TRAIL_PARTY_H
#include "Person.h"
#include "inventory/Inventory.h"
#include <vector>

class Party {
    public:
        Party();
        virtual ~Party();

        Person& getPartyMember(int index);
        int getPartySize() const;
    
    private:
        std::vector<Person> _members;
        int _partySize = 4;
        Inventory _inventory;
};

#endif