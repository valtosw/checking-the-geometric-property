#include <iostream>
#include "quadrangle.h"
typedef std::pair<geometry::Point, geometry::Point> Segment;
typedef std::vector<Segment> Segments;

bool quadrangle::doQuadranglesIntersect(Quadrangle& quad1, Quadrangle& quad2){
    geometry::Point A1 = quad1.A, B1 = quad1.B, C1 = quad1.C, D1 = quad1.D;
    geometry::Point A2 = quad2.A, B2 = quad2.B, C2 = quad2.C, D2 = quad2.D;

    Segments segments1 = {{A1, B1}, {B1, C1}, {C1, D1}, {D1, A1}};
    Segments segments2 = {{A2, B2}, {B2, C2}, {C2, D2}, {D2, A2}};

    for (Segment& s1 : segments1){
        for (Segment& s2 : segments2){
            if (geometry::doSegmentsIntersect(s1.first, s1.second, s2.first, s2.second)){
                return true;
            }
        }
    }

    return false;
}

bool quadrangle::operator^(quadrangle::Quadrangle& quad1, quadrangle::Quadrangle& quad2){
    return quadrangle::doQuadranglesIntersect(quad1, quad2);
}