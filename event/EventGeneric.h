#ifndef TEXAS_TRAIL_EFFECT_GENERIC_H
#define TEXAS_TRAIL_EFFECT_GENERIC_H
#include "event/Event.h"
#include "DialoguePrompt.h"

class EventGeneric : public Event {
    public:
        EventGeneric() : Event() { _popup = StringList({"Bob has broken a leg!!"}); }
        virtual ~EventGeneric() {}

        virtual StringList& popup() override;
        virtual DialoguePrompt* prompt() override;
        virtual void callback(int ret) override;
};

#endif