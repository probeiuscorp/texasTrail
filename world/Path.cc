#include "Path.h"
#include "Utils.h"
#include "Enums.h"
#include <math.h>

Path::Path(Node& nodeFrom, Node& nodeTo, const Biome& biome) : _nodeFrom(nodeFrom), _nodeTo(nodeTo), _biome(biome) {
    nodeFrom.addPath(this);
    nodeTo.addPath(this);
    float a = nodeFrom.x() - nodeTo.x();
    float b = nodeFrom.y() - nodeTo.y();
    _distance = std::sqrt((a*a)+(b*b));
};
Path::~Path(){};

string Path::name() {
    return string(_nodeTo.feature().name() + " - " + Utils::stringifyAndRound(_distance,1) + ", " + Utils::toLower(Enums::toString(_biome.enumType()))); // Austin (City) - 5.8mi, desert
}