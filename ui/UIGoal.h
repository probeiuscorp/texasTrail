#ifndef TEXAS_TRAIL_UI_GOAL_H
#define TEXAS_TRAIL_UI_GOAL_H
#include "Log.h"
#include "Colors.h"
#include "Formatting.h"
#include "world/EndNode.h"

class UI;
class UIGoal {
    public:
        UIGoal(EndNode& goal, UI& ui);
        virtual ~UIGoal() {}

        void run();

    private:
        EndNode& _goal;
        UI& _ui;
};

#endif