#ifndef TEXAS_TRAIL_POINT_H
#define TEXAS_TRAIL_POINT_H

class Point {
    public:
        Point(double x, double y) { _x = x; _y = y; }
        virtual ~Point() {}

        virtual double x() { return _x; }
        virtual double y() { return _y; }
    
    private:
        double _x;
        double _y;
};

#endif