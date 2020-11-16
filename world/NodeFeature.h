#ifndef TEXAS_TRAIL_NODE_FEATURE_H
#define TEXAS_TRAIL_NODE_FEATURE_H
#include "Party.h"

class NodeFeature {
    public:
        NodeFeature();
        virtual ~NodeFeature();

        virtual void onArrival(Party& party) = 0;
};

#endif