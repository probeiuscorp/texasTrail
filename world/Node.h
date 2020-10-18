#ifndef TEXAS_TRAIL_NODE_H
#define TEXAS_TRAIL_NODE_H
#include "NodeFeature.h"
#include "TreeElement.h"
#include <vector>
using std::vector;

class Path;

class Node : public TreeElement {
    public:
        using PathList = vector<Path*>;

    public:
        Node(NodeFeature* feature);
        virtual ~Node();

        NodeFeature& getFeature() { return *_feature; }
        void addPath(Path* path);
    private:
        NodeFeature* _feature = nullptr;
        PathList _paths;
};

#endif