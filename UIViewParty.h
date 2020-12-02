#ifndef TEXAS_TRAIL_UI_VIEW_PARTY_H
#define TEXAS_TRAIL_UI_VIEW_PARTY_H

class Party;
class Person;
class TexasTrail;
class UI;
class UIViewParty {
    public:
        UIViewParty(Party& party, UI& ui) : _party(party), _ui(ui) {}
        virtual ~UIViewParty() {}

        virtual void run();
    
    private:
        Party& _party;
        UI& _ui;

        virtual void setUIViewPerson(Person& person);
};

#endif