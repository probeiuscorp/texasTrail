#ifndef TEXAS_TRAIL_ROAD_FORK_H
#define TEXAS_TRAIL_ROAD_FORK_H
#include "world/NodeFeature.h"
#include <string>
using std::string;

class RoadFork : public NodeFeature {
    public:
        RoadFork(int numPathsTo);
        virtual ~RoadFork();

        virtual string name();

    private:
        int _numPathsTo;
};

#endif