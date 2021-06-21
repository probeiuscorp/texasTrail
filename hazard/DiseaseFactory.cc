#include "DiseaseFactory.h"
#include "EffectDisease.h"
#include "Utils.h"

DiseaseFactory& DiseaseFactory::start() {
    return *(new DiseaseFactory());
}

DiseaseFactory& DiseaseFactory::setName(string name) {
    _name = name;
    return *this;
}

DiseaseFactory& DiseaseFactory::setDisplay(string display) {
    _display = display;
    return *this;
}

DiseaseFactory& DiseaseFactory::setDamage(double damage) {
    _damage = damage;
    return *this;
}

DiseaseFactory& DiseaseFactory::setCommon(double common) {
    _common = common;
    return *this;
}

DiseaseFactory& DiseaseFactory::setInfectivity(double infectious) {
    _infectious = infectious;
    return *this;
}

DiseaseFactory& DiseaseFactory::setCurability(double curability) {
    _curability = curability;
    return *this;
}

HazardDisease* DiseaseFactory::create() {
    EffectDisease* effect = new EffectDisease(_damage, _curability, _name, _display);
    HazardDisease* hazard = new HazardDisease(_infectious, _common, _name, effect);
    Hazards::registerPersonHazard(hazard);
    return hazard;
}