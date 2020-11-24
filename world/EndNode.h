#ifndef TEXAS_TRAIL_END_NODE_H
#define TEXAS_TRAIL_END_NODE_H
#include "world/NodeFeature.h"

class EndNode : public NodeFeature {
    public:
        EndNode(string name) : NodeFeature(NodeFeature::EnumFeature::GOAL) { _name = name; }
        virtual ~EndNode() {}

        virtual string name();

    private:
        string _name;
};

#endif