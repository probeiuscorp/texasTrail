#ifndef TEXAS_TRAIL_SEGMENT_H
#define TEXAS_TRAIL_SEGMENT_H
#include "Point.h"

class Segment {
    public:
        Segment(Point* start, Point* end);
        virtual ~Segment() {}

        virtual Point* start() { return _start; }
        virtual Point* end() { return _end; }
        virtual double length();

        static Point* intersection(Segment* one, Segment* two);

    private:
        Point* _start;
        Point* _end;
};

#endif