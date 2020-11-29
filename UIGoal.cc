#include "UIGoal.h"
#include "UI.h"

UIGoal::UIGoal(EndNode& goal, UI& ui) : _goal(goal), _ui(ui) {}

void UIGoal::run() {
    _ui.clean();
    Log::log("\n You reached %s%s" __RESET "!\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), _goal.name().c_str());
    Log::log(" Your score: %s", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str());
    Log::log("%d\n\n", 2000);
}