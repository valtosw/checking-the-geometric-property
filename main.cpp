#include <iostream>
#include "print.h"
#include "geom.h"
#include "quadrangle.h"

int main() {
    std::vector<geometry::Point> points1(4), points2(4);

    logging::printInfo();
    geometry::getAllPoints(points1, points2);

    quadrangle::Quadrangle quad1{points1[0], points1[1], points1[2], points1[3]};
    quadrangle::Quadrangle quad2{points2[0], points2[1], points2[2], points2[3]};

    logging::result(quad1^quad2);
    logging::close();

    return 0;
}
