#ifndef TEXAS_TRAIL_EVENT_H
#define TEXAS_TRAIL_EVENT_H
#include "DialoguePrompt.h"

class Event {
    public:
        using StringList = DialoguePrompt::StringList;

    protected:
        Event() {}

    public:
        virtual ~Event() {}

        virtual StringList& popup() = 0;
        virtual DialoguePrompt* prompt() = 0;
        virtual void callback(int ret) = 0;

    protected:
        StringList _popup = StringList({""});
        DialoguePrompt* _prompt;
};

#endif