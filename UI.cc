#include "UI.h"
#include "DialoguePrompt.h"
#include "TexasTrail.h"
#include "Settings.h"
#include "StringPrompt.h"
#include "Log.h"
#include <string>
using Menu = UI::Menu;
using StringList = DialoguePrompt::StringList;
using Difficulty = Settings::Difficulty;

UI::UI(TexasTrail& game) : _game(game) {};
UI::~UI(){};

UI::Menu UI::getUI() {
    return _menu;
};

void UI::init() {
    printTitle();
    setUIMain();
}

void UI::setUIMain() {
    _menu = Menu::MAIN;
    DialoguePrompt prompt(string("Welcome to the Texas Trail! What would you like to do?"), StringList({"Start a new journey","Load from a save","Exit"}));
    switch(prompt.execute()) {
        case 1:
            setUINewGame();
            break;
        case 2:
            setUILoad();
            break;
        case 3:
            _game.exit(0);
            break;
    }
}

void UI::setUILoad() {
    _menu = Menu::LOAD;
}

void UI::setUINewGame() {
    _menu = Menu::NEW_GAME;
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

    StringPrompt prompt(string("Who is in your party?"), StringList({": ",": ",": ",": "}));
    StringList names = prompt.execute();

    // tell game to change party's names

    setUIConfirmNewGame();
}

void UI::setUIConfirmNewGame() {
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

    DialoguePrompt prompt(str, StringList({"Confirm","Retry","Cancel"}));
    switch(prompt.execute()) {
        case 1:
            break;
        case 2:
            setUINewGame();
            break;
        case 3:
            setUIMain();
            break;
    }
}

void UI::printTitle() const {
    Log::log("\n\n");
    Log::log("::::::::::: :::::::::: :::    :::     :::      ::::::::       ::::::::::: :::::::::      :::     ::::::::::: :::\n    :+:     :+:        :+:    :+:   :+: :+:   :+:    :+:          :+:     :+:    :+:   :+: :+:       :+:     :+:\n    +:+     +:+         +:+  +:+   +:+   +:+  +:+                 +:+     +:+    +:+  +:+   +:+      +:+     +:+\n    +#+     +#++:++#     +#++:+   +#++:++#++: +#++:++#++          +#+     +#++:++#:  +#++:++#++:     +#+     +#+\n    +#+     +#+         +#+  +#+  +#+     +#+        +#+          +#+     +#+    +#+ +#+     +#+     +#+     +#+\n    #+#     #+#        #+#    #+# #+#     #+# #+#    #+#          #+#     #+#    #+# #+#     #+#     #+#     #+#\n    ###     ########## ###    ### ###     ###  ########           ###     ###    ### ###     ### ########### ##########\n");
    Log::log("\n\n");
}