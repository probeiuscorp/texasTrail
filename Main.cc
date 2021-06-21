#include <stdio.h>
#include <string>
#include "Settings.h"
#include "DialoguePrompt.h"
#include "TexasTrail.h"
#include "ui/UI.h"
#include "PersonGenerator.h"
#include "Hazards.h"

using StringList = DialoguePrompt::StringList;
using std::string;
using Difficulty = Settings::Difficulty;

int main(int argc, char** argv) {
    srand(time(nullptr));
    Hazards::load();
    PersonGenerator::load();
    TexasTrail texasTrail;
    UI ui(texasTrail);
    return ui.init();
}