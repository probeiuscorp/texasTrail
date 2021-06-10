#include "ui/UI.h"
#include "PersonGenerator.h"
#include <iostream>

UI::UI(TexasTrail& game) : _game(game) {};
UI::~UI(){};

UI::Menu UI::getUI() {
    return _menu;
};

int UI::init() {
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
    
    _people = PersonGenerator::generate(4);
    Log::log("%sYour party:\n" __RESET, Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str());
    for(Person* person : _people) {
        Log::log(" > %s\n", person->name().c_str());
    }
    Log::log(__GREEN "Press 'ENTER' to continue: " __RESET);
    std::cin.get();
    
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

    for(int i=0;i<_people.size();i++) {
        str += "'";
        str += _people[i]->name();
        str += "'";
        if(i != _people.size()-1) {
            str += ", ";
        }
    }
    
    DialoguePrompt prompt(str, StringList({"Confirm","Retry","Cancel"}));
    switch(prompt.execute()) {
        case 1: {
            setUIGame();
            break;
        }
        case 2:
            setUINewGame();
            break;
        case 3:
            setUIMain();
            break;
    }
}

void UI::setUIGame() {
    _game.generateWorld();
    _game.generateParty(_people);
    _game.party().setMoney(3000);
    _game.setTime(10,1,4,1838);
    PersonGenerator::unload();
    setUILoop();
}

void UI::setUILoop() {
    bool exit = false;
    while(!_exit) {
        Path* nextPath;
        switch(_game.party().node()->feature().type()) {
            case NodeFeature::EnumFeature::CITY: {
                UICity uiCity(_game, dynamic_cast<City&>(_game.party().node()->feature()), *this);
                nextPath = uiCity.run();
                break;
            }
            case NodeFeature::EnumFeature::GOAL: {
                UIGoal uiGoal(dynamic_cast<EndNode&>(_game.party().node()->feature()), *this);
                uiGoal.run();
                exit = true;
                break;
            }
            case NodeFeature::EnumFeature::FORK: {
                UIFork uiFork(_game, dynamic_cast<RoadFork&>(_game.party().node()->feature()), *this);
                nextPath = uiFork.run();
            }
        }
        if(exit) break;
        if(nextPath == nullptr) {
            break;
        }
        _game.party().setPath(nextPath);
        _game.party().setNode(nullptr);
        UITravel uiTravel(_game, *this);
        if(uiTravel.run()) {
            break;
        }
        _game.party().setPath(nullptr);
        _game.party().setNode(&(nextPath->nodeTo()));
    }
    // save game state
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

void UI::exit() {
    exit(0); 
}

void UI::exit(int exit_status) {
    _exit = true;
    _exit_status = exit_status; 
}