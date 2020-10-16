#ifndef TEXAS_TRAIL_WORLD_H
#define TEXAS_TRAIL_WORLD_H
#include "Node.h"
#include "TreeElement.h"
#include <vector>
using std::vector;

class World {
    public: 
        World();
        virtual ~World();

    private:
        using TreeElementList = vector<TreeElement*>;

    private:
        Node* _firstNode;
        TreeElementList _treeElementPool;

    private:
        void deleteTree();
};

#endif