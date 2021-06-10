#include "ui/UIFork.h"
#include "ui/UI.h"
#include "ui/UICommons.h"
#include "TexasTrail.h"

UIFork::UIFork(TexasTrail& game, RoadFork& fork, UI& ui) : _game(game), _fork(fork), _ui(ui) {}
UIFork::~UIFork() {}

Path* UIFork::run() {
    return UICommons::nextPathSelector(_game.party().node()->paths());
}