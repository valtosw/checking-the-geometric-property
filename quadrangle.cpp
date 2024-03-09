#include <iostream>
#include "quadrangle.h"
typedef std::vector<std::pair<geometry::Point, geometry::Point>> Segment;

bool quadrangle::doQuadranglesIntersect(Quadrangle& quad1, Quadrangle& quad2){
    geometry::Point A1 = quad1.A, B1 = quad1.B, C1 = quad1.C, D1 = quad1.D;
    geometry::Point A2 = quad2.A, B2 = quad2.B, C2 = quad2.C, D2 = quad2.D;

    Segment segments1 = {{A1, B1}, {B1, C1}, {C1, D1}, {D1, A1}};
    Segment segments2 = {{A2, B2}, {B2, C2}, {C2, D2}, {D2, A2}};

    for (auto& s1 : segments1){
        for (auto& s2 : segments2){
            if (geometry::doSegmentsIntersect(s1.first, s1.second, s2.first, s2.second)){
                return true;
            }
        }
    }

    return false;
}
