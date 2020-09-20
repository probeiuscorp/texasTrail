#include <stdio.h>
#include <string>
#include "Settings.h"
#include "DialoguePrompt.h"
#include "TexasTrail.h"
using StringList = DialoguePrompt::StringList;
using std::string;
using Difficulty = Settings::Difficulty;

int main(int argc, char** argv) {
    TexasTrail texasTrail;
    UI ui(texasTrail);
    ui.init();
    return texasTrail.run();
}