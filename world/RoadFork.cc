#include "RoadFork.h"

RoadFork::RoadFork(int numPathsTo) : NodeFeature(NodeFeature::EnumFeature::FORK) {}
RoadFork::~RoadFork() {}

string RoadFork::name() {
    return string("Fork in the road ("+std::to_string(_numPathsTo) + ")");
}