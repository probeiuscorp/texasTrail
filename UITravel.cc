#include "UITravel.h"

UITravel::UITravel(TexasTrail& game, const UI& ui) : _game(game), _ui(ui) {}
UITravel::~UITravel(){}

void UITravel::run() {
    setUITravel();
}

void UITravel::setUITravel() {
    Log::log("5/7/1876");
    Log::log(string("\n  \u256d"+Utils::numerateString("\u2500",8)+"\u2500\n").c_str());
}