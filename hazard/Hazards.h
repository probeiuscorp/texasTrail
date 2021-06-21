#ifndef TEXAS_TRAIL_HAZARDS_H
#define TEXAS_TRAIL_HAZARDS_H
#include <vector>
using std::vector;

class WagonHazard;
class PersonHazard;
class PartyHazard;
class Hazards {
    public:
        using WagonHazardList = vector<WagonHazard*>;
        using PersonHazardList = vector<PersonHazard*>;
        using PartyHazardList = vector<PartyHazard*>;

    public:
        static void registerWagonHazard(WagonHazard* hazard);
        static void registerPersonHazard(PersonHazard* hazard);
        static void registerPartyHazard(PartyHazard* hazard);
        static WagonHazardList& wagonHazards();
        static PersonHazardList& personHazards();
        static PartyHazardList& partyHazards();
        static void load();
    
    private:
        static WagonHazardList _wagonHazards;
        static PersonHazardList _personHazards;
        static PartyHazardList _partyHazards;
};

#endif