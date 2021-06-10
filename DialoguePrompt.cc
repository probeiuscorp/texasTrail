#include "DialoguePrompt.h"
#include <iostream>
#include <sstream>
#include "Log.h"
#include "Colors.h"
#include "Formatting.h"

DialoguePrompt::DialoguePrompt(const string& prompt, const StringList& choices) : _prompt(prompt), _choices(choices) {}
DialoguePrompt::~DialoguePrompt() {}

int DialoguePrompt::execute() const {
    Log::log("%s%s" __RESET "\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), _prompt.c_str());
    for(int i = 0;i<_choices.size();i++) {
        Log::log(" %d. %s\n", i+1, _choices[i].c_str());
    }
    
    Log::log("%sWhat is your choice? " __RESET, Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str());

    int chosen = -1;
    chosen = getResponse();

    while(!isValidResponse(chosen)) {
        Log::log( __RED "Invalid Response." __RESET " What is your choice? ");
        chosen = getResponse();
    }

    Log::log("\n");

    return chosen;
}

bool DialoguePrompt::isValidResponse(int response) const {
    bool r = true;

    if(response < 1 || response > _choices.size()) {
        r = false;
    }

    return r;
}

int DialoguePrompt::getResponse() const {
    int chosen = -1;
    string line;

    if(std::getline(std::cin, line)) {
        std::istringstream str(line);
        str >> chosen;
    }

    return chosen;
}