#ifndef TEXAS_TRAIL_PARTY_H
#define TEXAS_TRAIL_PARTY_H
#include "Person.h"
#include "inventory/Inventory.h"
#include "world/World.h"
#include "world/Path.h"
#include "Enums.h"
#include "event/Event.h"
#include "Wagon.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Party {
    public:
        using StringList = vector<string>;
        using EventList = Person::EventList;

    public:
        Party(vector<Person*> members, World& world);
        virtual ~Party();

        Person& getPartyMember(int index);
        int getPartySize() const;
        Inventory& inventory() { return _inventory; }
        const Inventory& CInventory() const { return _inventory; }
        Path* path() { return _path; }
        Node* node() { return _node; }
        void setNode(Node* node) { _node = node; }
        void setPath(Path* path) { _path = path; }
        double distance() const { return _distance; }
        Enums::Pace pace() const { return _pace; }
        void setPace(Enums::Pace pace) { _pace = pace; }
        Enums::Ration ration() const { return _ration; }
        void setRation(Enums::Ration ration) { _ration = ration; }
        double money() const { return _money; }
        void setMoney(double money) { _money = money; }
        bool modifyMoney(double moneyM);
        EventList tick(int hours);
        Wagon& wagon() { return _wagon; }

    private:
        int _partySize = 4;
        vector<Person*> _members;
        Inventory _inventory;
        World& _world;
        Wagon _wagon;

        Path* _path = nullptr;
        Node* _node = nullptr;
        double _distance = 0;
        double _money = 0;
        Enums::Pace _pace = Enums::Pace::NORMAL;
        Enums::Ration _ration = Enums::Ration::NORMAL;
};

#endif