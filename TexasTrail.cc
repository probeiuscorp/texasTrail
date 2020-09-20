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
    _exit = false;
    _settings = Settings();
}
TexasTrail::~TexasTrail() {}

int TexasTrail::run() {
    init();

    while(!_exit) {

    }

    return _exit_status;
}

void TexasTrail::init() {
    // printTitle();
}

void TexasTrail::setDifficulty(Difficulty difficulty) {
    _settings.setDifficulty(difficulty);
}

Settings::Difficulty TexasTrail::getDifficulty() {
    return _settings.getDifficulty();
}

void TexasTrail::exit(int exit_status) {
    _exit = true;
    _exit_status = exit_status;
}