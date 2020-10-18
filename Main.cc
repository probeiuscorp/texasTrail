#include <stdio.h>
#include <string>
#include "Settings.h"
#include "DialoguePrompt.h"
#include "TexasTrail.h"
#include "UI.h"
using StringList = DialoguePrompt::StringList;
using std::string;
using Difficulty = Settings::Difficulty;

int main(int argc, char** argv) {
    TexasTrail texasTrail;
    UI ui(texasTrail);
    return ui.init();
}