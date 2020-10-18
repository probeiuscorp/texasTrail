#include "Path.h"

Path::Path(Node& nodeFrom, Node& nodeTo) : _nodeFrom(nodeFrom), _nodeTo(nodeTo) {
    nodeFrom.addPath(this);
    nodeTo.addPath(this);
};
Path::~Path(){};