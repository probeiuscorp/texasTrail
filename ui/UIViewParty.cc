#include "ui/UIViewParty.h"
#include "ui/UI.h"
#include "DialoguePrompt.h"
#include "Utils.h"
#include "Person.h"
#include "Party.h"
#include "Colors.h"
#include "Formatting.h"
#include <string>
#include <iostream>
using std::string;

void UIViewParty::run() {
    while(true) {
        _ui.clean();
        DialoguePrompt::StringList sl({"Cancel"});
        for(int i=0;i<_party.getPartySize();i++) {
            // string str = Style::New(Formatting::Color::WHITE).with(Formatting::Format::UNDERLINE).text();
            Person& person = _party.getPartyMember(i);
            string str = __BOLD;
            str += person.name();
            str += " (";
            if(person.isDead()) {
                str += Style::New(Formatting::Color::RED).with(Formatting::Format::BOLD).text();
                str += "DEAD";
                str += __RESET __BOLD ")";
            } else {
                str += std::to_string((int)person.health());
                str += "% health, ";
                str += std::to_string((int)person.energy());
                str += "% energy)" __RESET;
            }
            if(!person.isDead()) {
                for(Effect* effect : person.effects()) {
                    str += "\n     > ";
                    str += effect->display(&person);
                }
            }
            sl.push_back(str);
        }
        DialoguePrompt prompt("Select party member", sl);
        int ret = prompt.execute();
        if(ret == 1) return;
        
        Person& person = _party.getPartyMember(ret-2);
        if(person.isDead()) {
            setUIViewDeadPerson(person);
        } else {
            setUIViewPerson(person);
        }
    }
}

void UIViewParty::setUIViewPerson(Person& person) {
    _ui.clean();

    DialoguePrompt prompt(string("What would you like to do with party member \""+person.name()+"\"?"), DialoguePrompt::StringList({"Cancel", "Put in wagon","Abandon (will remove from party permanently)","View immunity"}));
    switch(prompt.execute()) {
        case 2:
        case 3:
            break;
        case 4:
            setUIViewPersonImmunity(person);
            break;
    }
}

void UIViewParty::setUIViewDeadPerson(Person& person) {
    _ui.clean();
    DialoguePrompt prompt(string("What would you like to do with party member \""+person.name()+"\" (DEAD)?"), DialoguePrompt::StringList({"Cancel", "Abandon them", "Bury them (Takes time and energy)"}));
    switch(prompt.execute()) {
        case 2:
        case 3:
            break;
    }
}

void UIViewParty::setUIViewPersonImmunity(Person& person) {
    _ui.clean();
    Log::log("%s%s is immune to:\n" __RESET, Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), person.name().c_str());
    for(EffectDisease* effect : person.immunity().all()) {
        Log::log(" > %s\n", effect->name().c_str());
    }
    Log::log(__GREEN "Press 'ENTER' to continue " __RESET);
    std::cin.get();
}