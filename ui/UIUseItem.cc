#include "UIUseItem.h"
#include "DialoguePrompt.h"
#include "TablePrompt.h"

void UIUseItem::run() {
    while(true) {
        _ui.clean();
        DialoguePrompt prompt = DialoguePrompt("What would you like to use the item on?", StringList({"Party member", "Wagon", "Cancel"}));
        switch(prompt.execute()) {
            case 1:
                setUIPartyMember();
                break;
            case 2:
                setUIWagon();
                break;
            case 3:
                return;
        }
    }
}

void UIUseItem::setUIPartyMember() {
    StringList names;
    for(int i=0;i<_party.getPartySize();i++) {
        names.push_back(_party.getPartyMember(i).name());
    }
    _ui.clean();
    DialoguePrompt personPrompt = DialoguePrompt("Who would you like to use it on?", names);
    Person& person = _party.getPartyMember(personPrompt.execute()-1);

    _ui.clean();
    TablePrompt prompt = TablePrompt("What item would you like to use? (0 to leave)", {"Item","Count"});
    vector<Stack*> usableItems;
    for(Stack* stack : _party.wagon().stacks()) {
        if(stack->item().canBeUsedOnPerson() || true) {
            usableItems.push_back(stack);
        }
    }

    for(int i=0;i<usableItems.size();i++) {
        Stack* stack = usableItems[i];
        if(stack->item().usableOnPerson(&person)) {
            prompt.add(StringList({std::to_string(i+1) + ". " + stack->item().name(), std::to_string(stack->count())}));
        }
    }

    int ret = prompt.execute(4);
    if(ret != 0) {
        _ui.clean();
        Log::log("%s%s\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), 
            usableItems[ret-1]->item().useOnPerson(&person).c_str());
    }
}

void UIUseItem::setUIWagon() {

}