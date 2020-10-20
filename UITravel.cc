#include "UITravel.h"

UITravel::UITravel(TexasTrail& game, const UI& ui) : _game(game), _ui(ui) {
    readFrame(Resources::WAGON_FRAME_0, &_wagonFrame0);
    readFrame(Resources::WAGON_FRAME_1, &_wagonFrame1);
}
UITravel::~UITravel(){}

void UITravel::run() {
    while(!_exit) {
        setUITravel();
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        _frame = !_frame;
    }
}

void UITravel::setUITravel() {
    _ui.clean();

    string date = "5/7/1834 4:00 AM";
    if(_frame) {
        date = "5/7/1834 6:00 AM";
    }
    vector<string> meterPlateValues = vector<string>({"HEALTH: xxxx::::::","MORALE: xxxxxxx:::", "RESRVD: ----------", "RESRVD: ----------"});
    vector<string> conditionsPlateValues;

    Log::log("    %s%s\n", Utils::numerateString(" ", _plateSize+_windowSize/2-date.size()/2).c_str(), date.c_str());
    Log::log("    %s\u256d%s\u256e\n", Utils::numerateString(" ",_plateSize).c_str(), Utils::numerateString("\u2500", _windowSize).c_str());
    Log::log("  \u256d%s\u256e\u2502%s\u2502\u256d%s\u256e\n",Utils::numerateString("\u2500",_plateSize).c_str(), Utils::numerateString(" ", _windowSize).c_str(),Utils::numerateString("\u2500",_plateSize).c_str());
    for(int i=0;i<meterPlateValues.size();i++) {
        // Meters plate
        Log::log("  \u2502 %s%s\u2502", meterPlateValues[i].c_str(), Utils::numerateString(" ", _plateSize-meterPlateValues[i].size()-1).c_str());
        // Center window
        if(i < _wagonFrame0.size()) {
            Log::log("\u2502%s\u2502\n", _frame ? _wagonFrame0[i].c_str() : _wagonFrame1[i].c_str());
        }
    }
    Log::log("  \u2570%s\u256f",Utils::numerateString("\u2500",_plateSize).c_str());
    if(meterPlateValues.size() < _wagonFrame0.size()) {
        Log::log("\u2502%s\u2502", _frame ? _wagonFrame0[meterPlateValues.size()].c_str() : _wagonFrame1[meterPlateValues.size()].c_str());
    }
    Log::log("\n");

    for(int i=meterPlateValues.size()+1;i<_wagonFrame0.size()-1;i++) {
        Log::log("    %s", Utils::numerateString(" ",_plateSize).c_str());
        Log::log("\u2502%s\u2502\n", _frame ? _wagonFrame0[i].c_str() : _wagonFrame1[i].c_str());
    }
    // if(meterPlateValues.size() < _wagonFrame0.size()) {
        Log::log("    %s\u2570%s\u256f\n", Utils::numerateString(" ", _plateSize).c_str(), Utils::numerateString("\u2500",_windowSize).c_str());
    // }
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