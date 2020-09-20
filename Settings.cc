#include "Settings.h"

Settings::Settings() {}
Settings::~Settings() {}

void Settings::setDifficulty(Difficulty difficulty) {
    _difficulty = difficulty;
}
Settings::Difficulty Settings::getDifficulty() {
    return _difficulty;
}
