#include "IntPrompt.h"

IntPrompt::IntPrompt(const std::string& prompt, int min, int max) : _prompt(prompt), _min(min), _max(max) {}
IntPrompt::~IntPrompt(){}

int IntPrompt::execute() const {
    Log::log("%s%s" __RESET "\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), _prompt.c_str());
    Log::log("%s > " __RESET, Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str());

    int chosen = -1;
    chosen = getResponse();

    while(!isValidResponse(chosen)) {
        Log::log( __RED "Invalid Response." __RESET " What is your choice? ");
        chosen = getResponse();
    }

    Log::log("\n");

    return chosen;
}

bool IntPrompt::isValidResponse(int response) const {
    bool r = true;

    if(response < _min || response > _max) {
        r = false;
    }

    return r;
}

int IntPrompt::getResponse() const {
    int chosen = -1;
    std::string line;

    if(std::getline(std::cin, line)) {
        std::istringstream str(line);
        str >> chosen;
    }

    return chosen;
}