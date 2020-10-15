#include "UI.h"
#include "DialoguePrompt.h"
#include "TexasTrail.h"
#include "Settings.h"
#include "StringPrompt.h"
#include "Log.h"
#include "world/City.h"
#include "UICity.h"
#include <string>

using Menu = UI::Menu;
using StringList = DialoguePrompt::StringList;
using Difficulty = Settings::Difficulty;

UI::UI(TexasTrail& game) : _game(game) {};
UI::~UI(){};

UI::Menu UI::getUI() {
    return _menu;
};

int UI::init() {
    // printTitle();
    setUIMain();
    return _exit_status;
}

void UI::setUIMain() {
    _menu = Menu::MAIN;
    clean();

    DialoguePrompt prompt(string("Welcome to the Texas Trail! What would you like to do?"), StringList({"Start a new journey","Load from a save","Exit"}));
    switch(prompt.execute()) {
        case 1:
            setUINewGame();
            break;
        case 2:
            setUILoad();
            break;
        case 3:
            exit(0);
            break;
    }
}

void UI::setUILoad() {
    _menu = Menu::LOAD;
}

void UI::setUINewGame() {
    _menu = Menu::NEW_GAME;
    clean();

    DialoguePrompt prompt(string("Please choose difficulty"), StringList({"Easy","Medium","Hard","Nevermind, return to main menu"}));
    switch(prompt.execute()) {
        case 1:
            _game.setDifficulty(Difficulty::EASY);
            setUIParty();
            break;
        case 2:
            _game.setDifficulty(Difficulty::MEDIUM);
            setUIParty();
            break;
        case 3:
            _game.setDifficulty(Difficulty::HARD);
            setUIParty();
            break;
        case 4:
            setUIMain();
            break;
    }
}

void UI::setUIParty() {
    _menu = Menu::PARTY;
    clean();

    StringPrompt prompt(string("Who is in your party?"), StringList({": ",": ",": ",": "}));
    StringList names = prompt.execute();
    Party& party = _game.getParty();
    for(int i=0;i<names.size();i++) {
        party.getPartyMember(i).setName(names[i]);
    }
    
    setUIConfirmNewGame();
}

void UI::setUIConfirmNewGame() {
    _menu = Menu::NEW_GAME;
    clean();

    string str("Confirm game setup: ");
    switch(_game.getDifficulty()) {
        case Difficulty::EASY:
            str += "EASY; ";
            break;
        case Difficulty::MEDIUM:
            str += "MEDIUM; ";
            break;
        case Difficulty::HARD:
            str += "HARD; ";
            break;
    }

    Party& party = _game.getParty();
    for(int i=0;i<party.getPartySize();i++) {
        str += "'";
        str += party.getPartyMember(i).getName();
        str += "'";
        if(i != party.getPartySize()-1) {
            str += ", ";
        }
    }
    
    DialoguePrompt prompt(str, StringList({"Confirm","Retry","Cancel"}));
    City city;
    UICity uiCity(_game, city, *this);
    switch(prompt.execute()) {
        case 1:
            uiCity.run();
            break;
        case 2:
            setUINewGame();
            break;
        case 3:
            setUIMain();
            break;
    }
}

void UI::clean() const {
    Log::log("\033[2J\033[1;1H");
    printTitle();
}

void UI::printTitle() const {
    Log::log("\n\n");
    Log::log("::::::::::: :::::::::: :::    :::     :::      ::::::::       ::::::::::: :::::::::      :::     ::::::::::: :::\n    :+:     :+:        :+:    :+:   :+: :+:   :+:    :+:          :+:     :+:    :+:   :+: :+:       :+:     :+:\n    +:+     +:+         +:+  +:+   +:+   +:+  +:+                 +:+     +:+    +:+  +:+   +:+      +:+     +:+\n    +#+     +#++:++#     +#++:+   +#++:++#++: +#++:++#++          +#+     +#++:++#:  +#++:++#++:     +#+     +#+\n    +#+     +#+         +#+  +#+  +#+     +#+        +#+          +#+     +#+    +#+ +#+     +#+     +#+     +#+\n    #+#     #+#        #+#    #+# #+#     #+# #+#    #+#          #+#     #+#    #+# #+#     #+#     #+#     #+#\n    ###     ########## ###    ### ###     ###  ########           ###     ###    ### ###     ### ########### ##########\n");
    Log::log("\n\n");
}

void UI::exit(int exit_status) {
    _exit_status = exit_status; 
}