#include "Hazards.h"
#include "HazardWagonFire.h"
#include "Diseases.h"

Hazards::WagonHazardList Hazards::_wagonHazards = Hazards::WagonHazardList();
Hazards::PartyHazardList Hazards::_partyHazards = Hazards::PartyHazardList();
Hazards::PersonHazardList Hazards::_personHazards = Hazards::PersonHazardList();

void Hazards::registerWagonHazard(WagonHazard* wagonHazard) {
    _wagonHazards.push_back(wagonHazard);
}

void Hazards::registerPersonHazard(PersonHazard* personHazard) {
    _personHazards.push_back(personHazard);
}

void Hazards::registerPartyHazard(PartyHazard* partyHazards) {
    _partyHazards.push_back(partyHazards);
}

Hazards::WagonHazardList& Hazards::wagonHazards() {
    return _wagonHazards;
}

Hazards::PersonHazardList& Hazards::personHazards() {
    return _personHazards;
}

Hazards::PartyHazardList& Hazards::partyHazards() {
    return _partyHazards;
}

void Hazards::load() {
    Diseases::load();
    registerWagonHazard(new HazardWagonFire());
}