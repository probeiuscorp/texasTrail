#include "Segment.h"
#include "Utils.h"
#include <math.h>

Segment::Segment(Point* start, Point* end) {
    _start = start;
    _end = end;
}

double Segment::length() {
    return sqrt(pow(_end->x()-_start->y(), 2) + pow(_end->y()-_start->y(), 2));
} 

Point* Segment::intersection(Segment* one, Segment* two) {
    double a1 = one->end()->y() - one->start()->y();
    double b1 = one->start()->x() - one->end()->x();
    double c1 = a1 * one->start()->x() + b1 * one->start()->y();
    
    double a2 = two->end()->y() - two->start()->y();
    double b2 = two->start()->x() - two->end()->x();
    double c2 = a2 * two->start()->x() + b2 * two->start()->y();

    double determinant = a1*b2 - a2*b1;

    if(determinant == 0) { 
        printf("Determinant is 0\n");
        return nullptr;
    } else {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        printf("X: %.8f, Y: %.8f\n", x, y);
        double minX = Utils::min(4, one->start()->x(), one->end()->x(), two->start()->x(), two->end()->x());
        double minY = Utils::min(4, one->start()->y(), one->end()->y(), two->start()->y(), two->end()->y());
        double maxX = Utils::max(4, one->start()->x(), one->end()->x(), two->start()->x(), two->end()->x());
        double maxY = Utils::max(4, one->start()->y(), one->end()->y(), two->start()->y(), two->end()->y());
        printf("minX: %.8f, minY: %.8f, maxX: %.8f, MaxY: %.8f\n", minX, minY, maxX, maxY);
        printf("%d %d %d %d\n", x < minX, x > maxX, y < minY, y > maxY);
        if(x < minX || x > maxX || y < minY || y > maxY) return nullptr;
        return new Point(x, y);
    }
}