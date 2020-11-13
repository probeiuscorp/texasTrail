#include "TexasTrail.h"

TexasTrail::TexasTrail() {
    _settings = Settings();
}
TexasTrail::~TexasTrail() {
    delete _world;
    delete _party;
}

World* TexasTrail::generateWorld() {
    WorldGenerator generator;
    return generator.generateWorld();
}

void TexasTrail::generateParty(StringList names) {
    if(_world != nullptr) {
        _party = new Party(names, *_world);
    } else {
        printf("World is not yet generated. Party creation aborted.\n");
    }
}

City& TexasTrail::startingCity() {
    return dynamic_cast<City&>(_world->startingNode().getFeature());
}

void TexasTrail::tick(int hours) {
    _date.advance(hours);
}