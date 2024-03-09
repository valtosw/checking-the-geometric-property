#pragma once
#include "geom.h"
namespace quadrangle{
    struct Quadrangle{ geometry::Point A, B, C, D; };
    bool doQuadranglesIntersect(Quadrangle& quad1, Quadrangle& quad2);
}