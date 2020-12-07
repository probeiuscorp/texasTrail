#include "TexasTrail.h"

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

void TexasTrail::generateParty(StringList names) {
    if(_world != nullptr) {
        _party = new Party(names, *_world);
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
    for(Event* event : _party->tick(hours)) {
        _events.push_back(event);
    }
    return _events;
}