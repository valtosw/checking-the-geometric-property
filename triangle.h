#pragma onceonce
#include "geom.h"

namespace triangle{
    struct Triangle{
        geometry::Point A, B, C;
    };

    double triangleArea(Triangle triangle);
}