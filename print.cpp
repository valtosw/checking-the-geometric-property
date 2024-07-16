#include <iostream>
#include "print.h"

void logging::printInfo() {
    std::cout << "Bessarabov Volodymyr  K-14\n";
    std::cout << "Variant 10: Do two quadrangles intersect?\n";
}

void logging::result(bool intersection){
    std::cout << (intersection? "The quadrangles intersect.\n" : "The quadrangles do not intersect.\n");
}

void logging::close() {
    std::cout << "Goodbye!\n";
}