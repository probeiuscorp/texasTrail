#ifndef TEXAS_TRAIL_PATH_H
#define TEXAS_TRAIL_PATH_H
#include "Node.h"

class Path : public TreeElement {
    public:
        Path(Node& nodeFrom, Node& nodeTo);
        virtual ~Path();
        
    private:
        Node& _nodeFrom;
        Node& _nodeTo;
};

#endif