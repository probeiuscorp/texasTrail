#ifndef TEXAS_TRAIL_WAGON_H
#define TEXAS_TRAIL_WAGON_H
#include "Inventory.h"
#include "Hazard.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Stack;
class Event;
class Wagon : public Inventory {
    public:
        Wagon(double maxWeight) : Inventory(maxWeight) {}
        virtual ~Wagon() {}

        static void registerHazard(WagonHazard* hazard) { _hazards.push_back(hazard); }
        static vector<WagonHazard*> hazards() { return _hazards; }

        virtual vector<Event*> tick(int hours);
        virtual void addEvent(Event* event) { _events.push_back(event); }
        virtual vector<Event*>& events() { return _events; }
        virtual void clearEvents();

    private:
        static vector<WagonHazard*> _hazards;

        vector<Event*> _events;
};

#endif