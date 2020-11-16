#ifndef TEXAS_TRAIL_PARTY_H
#define TEXAS_TRAIL_PARTY_H
#include "Person.h"
#include "inventory/Inventory.h"
#include "world/World.h"
#include "world/Path.h"
#include "Enums.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Party {
    public:
        using StringList = vector<string>;

    public:
        Party(StringList names, World& world);
        virtual ~Party();

        Person& getPartyMember(int index);
        int getPartySize() const;
        Inventory& inventory() { return _inventory; }
        const Inventory& CInventory() const { return _inventory; }
        Path& path() { return *_path; }
        double distance() { return _distance; }

    private:
        int _partySize = 4;
        vector<Person> _members;
        Inventory _inventory;
        World& _world;

        Path* _path;
        double _distance;
        Enums::Pace _pace;
};

#endif