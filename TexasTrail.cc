#include "TexasTrail.h"

TexasTrail::TexasTrail() {
    _settings = Settings();
    _party = Party();
}
TexasTrail::~TexasTrail() {}

World* TexasTrail::generateWorld() {
    WorldGenerator generator;
    return generator.generateWorld();
}
City& TexasTrail::startingCity() {
    return dynamic_cast<City&>(_world->startingNode().getFeature());
}

void TexasTrail::tick(int hours) {
    _date.advance(hours);
}