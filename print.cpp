#include <iostream>
#include "print.h"

void logging::printInfo() {
    std::cout << "Do two quadrangles intersect?\n";
}

void logging::result(quadrangle::Quadrangle& quad1, quadrangle::Quadrangle& quad2){
    if (quadrangle::doQuadranglesIntersect(quad1, quad2)){
        std::cout << "\nThe quadrangles intersect.\n";
    } else {
        std::cout << "\nThe quadrangles do not intersect.\n";
    }
}

void logging::close() {
    std::cout << "Goodbye!\n";
}