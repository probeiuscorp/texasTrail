#include "UIViewParty.h"
#include "UI.h"
#include "DialoguePrompt.h"
#include "Utils.h"
#include "Person.h"
#include "Party.h"
#include "Colors.h"
#include "Formatting.h"
#include <string>
using std::string;

void UIViewParty::run() {
    _ui.clean();

    DialoguePrompt::StringList sl({"Cancel"});
    for(int i=0;i<_party.getPartySize();i++) {
        // string str = Style::New(Formatting::Color::WHITE).with(Formatting::Format::UNDERLINE).text();
        string str = __BOLD;
        str += _party.getPartyMember(i).name();
        str += " (";
        str += std::to_string((int)_party.getPartyMember(i).health());
        str += "% health, ";
        str += std::to_string((int)_party.getPartyMember(i).energy());
        str += "% energy)" __RESET;
        for(Effect* effect : _party.getPartyMember(i).effects()) {
            str += "\n     > ";
            str += effect->display();
        }
        sl.push_back(str);
    }
    DialoguePrompt prompt("Select party member", sl);
    int ret = prompt.execute();
    if(ret != 1) {
        setUIViewPerson(_party.getPartyMember(ret-2));
    }
}

void UIViewParty::setUIViewPerson(Person& person) {
    _ui.clean();

    DialoguePrompt prompt(string("What would you like to do with party member \""+person.name()+"\"?"), DialoguePrompt::StringList({"Cancel", "Put in wagon","Abandon (will remove from party permanently)"}));
    switch(prompt.execute()) {
        
    }
    run();
}