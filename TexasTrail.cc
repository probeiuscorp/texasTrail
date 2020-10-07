#include <stdio.h>
#include <string>
#include "Settings.h"
#include "TexasTrail.h"
#include "DialoguePrompt.h"
#include "Log.h"
#include "Colors.h"
using StringList = DialoguePrompt::StringList;
using std::string;

TexasTrail::TexasTrail() {
    _settings = Settings();
    _party = Party();
}
TexasTrail::~TexasTrail() {}

void TexasTrail::setDifficulty(Difficulty difficulty) {
    _settings.setDifficulty(difficulty);
}

Settings::Difficulty TexasTrail::getDifficulty() {
    return _settings.getDifficulty();
}

Party& TexasTrail::getParty() {
    return _party;
};