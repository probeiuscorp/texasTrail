#include "Path.h"

Path::Path(Node& nodeFrom, Node& nodeTo, int distance, const Biome& biome) : _nodeFrom(nodeFrom), _nodeTo(nodeTo), _distance(distance), _biome(biome) {
    nodeFrom.addPath(this);
    nodeTo.addPath(this);
};
Path::~Path(){};