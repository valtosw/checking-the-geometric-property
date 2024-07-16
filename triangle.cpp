#include <iostream>
#include <cmath>
#include "triangle.h"

double triangle::triangleArea(Triangle triangle){
    geometry::Point A = triangle.A, B = triangle.B, C = triangle.C;
    return fabs((A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y))/2.0);
}