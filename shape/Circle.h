#ifndef TEXAS_TRAIL_CIRCLE_H
#define TEXAS_TRAIL_CIRCLE_H
#include <vector>
using std::vector;

class Point;
class Circle {
    public:
        Circle(Point* center, double radius) { _center = center; _radius = radius; }
        virtual Point* center() const { return _center; }
        virtual double radius() const { return _radius; }
        virtual Point* randomPointInside() const;

        static vector<Point*> intersect(Circle* one, Circle* two);

    private:
        Point* _center;
        double _radius;
};

#endif