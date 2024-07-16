#pragma once
#include "geom.h"
namespace quadrangle{
    struct Quadrangle{
        geometry::Point A, B, C, D;
        friend bool operator^(Quadrangle& q1, Quadrangle& q2);
    };
    bool doQuadranglesIntersect(Quadrangle& quad1, Quadrangle& quad2);
}