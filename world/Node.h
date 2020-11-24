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
        Node(NodeFeature* feature, double x, double y);
        virtual ~Node();

        NodeFeature& feature() { return *_feature; }
        PathList& paths() { return _paths; } 
        void addPath(Path* path);
        double x() { return _x; }
        double y() { return _y; }

    private:
        NodeFeature* _feature = nullptr;
        PathList _paths;
        double _x;
        double _y;
};

#endif