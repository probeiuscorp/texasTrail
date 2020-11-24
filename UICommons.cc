#include "UICommons.h"

Path* UICommons::nextPathSelector(Node::PathList paths) {
    DialoguePrompt::StringList opts({"Cancel"});
    for(Path* path : paths) {
        opts.push_back(path->name());
    }
    DialoguePrompt prompt("Where would you like to travel?", opts);
    int ret = prompt.execute();
    if(ret == 1) {
        return nullptr;
    } else {
        return paths[ret-2];
    }
}