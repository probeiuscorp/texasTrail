#include "UITravel.h"

UITravel::UITravel(TexasTrail& game, const UI& ui) : _game(game), _ui(ui), _window(SML_PANEL_WIDTH * 2 + LRG_PANEL_WIDTH, LRG_PANEL_HEIGHT), 
_leftPanel(SML_PANEL_WIDTH, SML_PANEL_HEIGHT), _rightPanel(SML_PANEL_WIDTH, SML_PANEL_HEIGHT), _animPanel(LRG_PANEL_WIDTH, LRG_PANEL_HEIGHT), 
_popupPanel(POP_PANEL_WIDTH, POP_PANEL_HEIGHT) {
    readFrame(Resources::WAGON_FRAME_0, &_wagonFrame0);
    readFrame(Resources::WAGON_FRAME_1, &_wagonFrame1);
    _leftPanel.setHeader("PARTY STATUS");
    _rightPanel.setHeader("ENVIRONMENT");
}
UITravel::~UITravel(){}

void UITravel::run() {
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
            std::getline(std::cin, _dummy);
            setUITravel(true);
        }
    }
}

void UITravel::setUITravel(bool paused) {
    _ui.clean();

    string date = _game.formattedTime();
    
    vector<string> meterPlateValues = vector<string>({"", "  HEALTH: xxxx::::::","  MORALE: xxxxxxx:::", "  RESRVD: ----------", "  RESRVD: ----------"});
    vector<string> conditionsPlateValues = vector<string>({"","  TEMPERATURE: 70F", "  HUMIDITY: 82%", "  BIOME: Mountains", "  DIST. LEFT: 17.1mi"});
    vector<string> popupContents = vector<string>({"","You have caught dysentary!"});

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
    } else {
        Log::log("\n");
        DialoguePrompt prompt = DialoguePrompt("What would you like to do?", DialoguePrompt::StringList({"Continue on the trail", "Check inventory", "Save & exit"}));
        switch(prompt.execute()) {
            case 1:
                run();
                break;
            case 2:
            case 3:
                _exit = true;
                break;
        }
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