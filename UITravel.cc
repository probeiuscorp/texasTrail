#include "UITravel.h"

UITravel::UITravel(TexasTrail& game, UI& ui) : _game(game), _ui(ui), _window(SML_PANEL_WIDTH * 2 + LRG_PANEL_WIDTH, LRG_PANEL_HEIGHT), 
_leftPanel(SML_PANEL_WIDTH, SML_PANEL_HEIGHT), _rightPanel(SML_PANEL_WIDTH, SML_PANEL_HEIGHT), _animPanel(LRG_PANEL_WIDTH, LRG_PANEL_HEIGHT), 
_popupPanel(POP_PANEL_WIDTH, POP_PANEL_HEIGHT) {
    readFrame(Resources::WAGON_FRAME_0, &_wagonFrame0);
    readFrame(Resources::WAGON_FRAME_1, &_wagonFrame1);
    _leftPanel.setHeader("PARTY STATUS");
    _rightPanel.setHeader("ENVIRONMENT");
}
UITravel::~UITravel(){}

bool UITravel::run() {
    setUITravel(false);
    while(!_exit) {
        struct pollfd fds[1];
        fds[0].fd = 0;
        fds[0].events = POLLIN;

        if(poll(fds, 1, 1000) == 0) {
            _game.tick(1);
            _hour = _game.date().hour();
            if(_hour >= 6 && _hour <= 22) {
                _frame = !_frame;
            }
            setUITravel(false);
        } else {
            // Consume ENTER
            std::getline(std::cin, _dummy);
            setUITravel(true);
            setUIStop();
            if(!_exit) setUITravel(false);
        }
        if(_game.party().path()->distance() <= _game.party().distance()) {
            return false;
        }
    }
    return true;
}

void UITravel::setUITravel(bool paused) {
    _ui.clean();

    string date = _game.formattedTime();
    
    vector<string> meterPlateValues = vector<string>({"", "  HEALTH: xxxx::::::","  MORALE: xxxxxxx:::"});
    vector<string> conditionsPlateValues = vector<string>({"","  TEMPERATURE: 70F", "  HUMIDITY: 82%", "  BIOME: Mountains"});
    vector<string> popupContents = vector<string>({"","You have caught dysentary!"});
    meterPlateValues.push_back(string("  PACE:   "+Enums::toString(_game.party().pace())));
    meterPlateValues.push_back(string("  RATION: "+Enums::toString(_game.party().ration())));
    meterPlateValues.push_back(string("  MONEY:  "+Utils::formatAsCurrency(_game.party().money())));
    string prettyDist = Utils::stringifyAndRound(_game.party().path()->distance() - _game.party().distance(),1);
    conditionsPlateValues.push_back(string("  DIST. LEFT: "+prettyDist+"mi"));

    _leftPanel.setContents(meterPlateValues);
    _animPanel.setContents(_frame ? _wagonFrame0 : _wagonFrame1);
    _rightPanel.setContents(conditionsPlateValues);
    _popupPanel.setContents(popupContents);

    _window.drawPanel(0, 2, _leftPanel);
    _window.drawPanel(SML_PANEL_WIDTH, 0, _animPanel);
    _window.drawPanel(RGT_PANEL_OFFSET, 2, _rightPanel);
    // _window.drawPanel(POP_PANEL_OFFSET_X, POP_PANEL_OFFSET_Y, _popupPanel);

    _window.setColorRect(SML_PANEL_WIDTH+1, LRG_PANEL_HEIGHT-4, LRG_PANEL_WIDTH-2, 3, __GREEN);
    _hour = _game.date().hour();
    
    if(_hour >= 9 && _hour <= 18) {
        _window.setColorRect(SML_PANEL_WIDTH+1, 1, LRG_PANEL_WIDTH-2, LRG_PANEL_HEIGHT-5, 52, 72, 81);
    } else if(_hour == 19) {
        _window.setColorRect(SML_PANEL_WIDTH+1, 1, LRG_PANEL_WIDTH-2, LRG_PANEL_HEIGHT-5, 34, 55, 60);
    } else if(_hour == 20) {
        _window.setColorRect(SML_PANEL_WIDTH+1, 1, LRG_PANEL_WIDTH-2, LRG_PANEL_HEIGHT-5, 16, 45, 45);
    } else if(_hour == 7) {
        _window.setColorRect(SML_PANEL_WIDTH+1, 1, LRG_PANEL_WIDTH-2, LRG_PANEL_HEIGHT-5, 16, 45, 45);
    } else if(_hour == 8) {
        _window.setColorRect(SML_PANEL_WIDTH+1, 1, LRG_PANEL_WIDTH-2, LRG_PANEL_HEIGHT-5, 34, 55, 60);
    } else {
        _window.setColorRect(SML_PANEL_WIDTH+1, 1, LRG_PANEL_WIDTH-2, LRG_PANEL_HEIGHT-5, __RESET);
    }
    
    Log::log("  %s%s%s" __RESET "\n", Utils::numerateString(" ", SML_PANEL_WIDTH+LRG_PANEL_WIDTH/2-ceil(date.size()/2.0)).c_str(), Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), date.c_str());
    _window.print(0);
    
    if(!paused) {
        Log::log("%s%sPress %s'ENTER'%s to stop" __RESET "\n", Utils::numerateString(" ", SML_PANEL_WIDTH+LRG_PANEL_WIDTH/2-10).c_str(), Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str(), 
                        Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str());
    }
}

void UITravel::setUIStop() {
    Log::log("\n");
    DialoguePrompt prompt = DialoguePrompt("What would you like to do?", DialoguePrompt::StringList({"Continue on the trail", "Check inventory", "Change pace", "Change rations","Save & exit"}));
    switch(prompt.execute()) {
        case 1:
            // run();
            break;
        case 2: {
            UIInventory uiInventory(_game.party().inventory(), _ui);
            uiInventory.run();
            // run();
            break;
        }
        case 3:
            setUIChoosePace();
            // run();
            break;
        case 4:
            setUIChooseRation();
            // run();
            break;
        case 5:
            _ui.exit();
            _exit = true;
            break;
    }
}

void UITravel::setUIChoosePace() {
    _ui.clean();
    setUITravel(true);
    Log::log("\n");
    DialoguePrompt prompt = DialoguePrompt("What will the pace be?", DialoguePrompt::StringList({"Cancel","Slow","Normal","Fast"}));
    switch(prompt.execute()) {
        case 2:
            _game.party().setPace(Enums::Pace::SLOW);
            break;
        case 3:
            _game.party().setPace(Enums::Pace::NORMAL);
            break;
        case 4:
            _game.party().setPace(Enums::Pace::FAST);
            break;
    }
}

void UITravel::setUIChooseRation() {
    _ui.clean();
    setUITravel(true);
    Log::log("\n");
    DialoguePrompt prompt = DialoguePrompt("What will the rations be?", DialoguePrompt::StringList({"Filling","Normal","Minimal","Cancel"}));
    switch(prompt.execute()) {
        case 1:
            _game.party().setRation(Enums::Ration::FILLING);
            break;
        case 2:
            _game.party().setRation(Enums::Ration::NORMAL);
            break;
        case 3:
            _game.party().setRation(Enums::Ration::MINIMAL);
            break;
    }
}

void UITravel::readFrame(const Resource& resource, vector<string>* array) const {
    std::ifstream fin;
    fin.open(resource.location(), std::ios::in);

    string line;
    while(fin) {
        getline(fin, line);
        (*array).push_back(line);
    }
}