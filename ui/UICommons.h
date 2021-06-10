#ifndef TEXAS_TRAIL_UI_COMMONS
#define TEXAS_TRAIL_UI_COMMONS
#include "world/Node.h"
#include "world/Path.h"
#include "Log.h"
#include "DialoguePrompt.h"

class UICommons {
    public:
        static Path* nextPathSelector(Node::PathList paths);
};

#endif