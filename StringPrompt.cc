#include "StringPrompt.h"
#include "Colors.h"
#include "Log.h"
#include <iostream>
#include <sstream>

StringPrompt::StringPrompt(const string& prompt, const StringList& choices) : _prompt(prompt), _choices(choices) {}
StringPrompt::~StringPrompt() {}

StringPrompt::StringList StringPrompt::execute() const {
    StringList responses;
    responses.reserve(_choices.size());
    Log::log("%s%s" __RESET "\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), _prompt.c_str());
    
    for(int i = 0;i<_choices.size();i++) {
        Log::log(" %s%s " __RESET, Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str(), _choices[i].c_str());
        responses.push_back(getResponse());
    }

    Log::log("\n");

    return responses;
}

string StringPrompt::getResponse() const {
    string line;
    std::getline(std::cin, line);
    return line;
}