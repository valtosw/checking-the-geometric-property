#include <iostream>
#include "print.h"

void logging::printInfo() {
    std::cout << "Do two quadrangles intersect?\n";
}

void logging::result(bool intersection){
    std::cout << (intersection? "The quadrangles intersect.\n" : "The quadrangles do not intersect.\n");
}

void logging::close() {
    std::cout << "Goodbye!\n";
}
