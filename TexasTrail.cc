#include "TexasTrail.h"
#include "Utils.h"
#include "Hazards.h"
#include <algorithm>

TexasTrail::TexasTrail() {
    _settings = Settings();
}
TexasTrail::~TexasTrail() {
    delete _world;
    delete _party;
}

void TexasTrail::generateWorld() {
    WorldGenerator generator;
    _world = generator.generateWorld();
}

void TexasTrail::generateParty(vector<Person*> people) {
    if(_world != nullptr) {
        _party = new Party(people, *_world);
        _party->setNode(&startingNode());
    } else {
        printf("World is not yet generated. Party creation aborted.\n");
    }
}

Node& TexasTrail::startingNode() {
    return _world->startingNode();
}

TexasTrail::EventList TexasTrail::tick(int hours) {
    _events.clear();
    _date.advance(hours);
    for(Event* event : _party->tick(hours, &_date)) {
        _events.push_back(event);
    }
    for(PartyHazard* partyHazard : Hazards::partyHazards()) {
        partyHazard->tryToApply(_party, this, hours);
    }
    for(Event* event : _party->wagon().tick(hours)) {
        _events.push_back(event);
    }
    for(WagonHazard* wagonHazard : Hazards::wagonHazards()) {
        wagonHazard->tryToApply(&_party->wagon(), this, hours); 
    }
    for(Event* event : _party->wagon().events()) {
        _events.push_back(event);
    }
    for(int i=0;i<_party->getPartySize();i++) {
        Person& person = _party->getPartyMember(i);
        for(Event* event : person.tick(hours)) {
            _events.push_back(event);
        }
        for(PersonHazard* personHazard : Hazards::personHazards()) {
            personHazard->tryToApply(&person, this, hours);
        }
        for(Event* event : person.events()) {
            _events.push_back(event);
        }
    }
    
    _party->clearEvents();
    std::random_shuffle(_events.begin(), _events.end());

    return _events;
}