#include "Circle.h"
#include "Point.h"
#include <stdlib.h>
#include <math.h>

Point* Circle::randomPointInside() const {
    double theta = (rand()/RAND_MAX)*2*M_PI;
    double r = (rand()/RAND_MAX)*_radius;
    return new Point(r * cos(theta), r * sin(theta));
}

vector<Point*> Circle::intersect(Circle* one, Circle* two) {
    vector<Point*> list;

    

    return list;
}