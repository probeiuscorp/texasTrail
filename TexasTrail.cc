#include "TexasTrail.h"

TexasTrail::TexasTrail() {
    _settings = Settings();
    _party = Party();
}
TexasTrail::~TexasTrail() {}

void TexasTrail::setDifficulty(Difficulty difficulty) {
    _settings.setDifficulty(difficulty);
}

void TexasTrail::setWorld(World* world) {
    _world = world;
}

Settings::Difficulty TexasTrail::getDifficulty() {
    return _settings.getDifficulty();
}

Party& TexasTrail::getParty() {
    return _party;
}

World* TexasTrail::generateWorld() {
    WorldGenerator generator;
    return generator.generateWorld();
}

City& TexasTrail::startingCity() {
    return dynamic_cast<City&>(_world->startingNode().getFeature());
}

void TexasTrail::tick(int hours) {
    
}