#include <iostream>
#include <set>
#include <cmath>
#include "geom.h"
#include "triangle.h"

void geometry::getPoints(std::vector<Point>& points1, const std::string& order){
    points1.clear();
    std::set<Point> unique_points1;
    std::cout << "\nEnter the coordinates of 4 points for the " << order << " quadrangle: \n";
    while (unique_points1.size() < 4){
        Point p{};
        if (!(std::cin >> p.x >> p.y) || !unique_points1.insert(p).second){
            std::cout << "Invalid input. Please input again: \n";
            points1.clear(); unique_points1.clear();
            std::cin.clear();
            std::cin.sync();
            continue;
        }
        points1.push_back(p);
    }

    std::cin.clear(); std::cin.sync();
}

void geometry::getAllPoints(std::vector<Point>& points1, std::vector<Point>& points2){
    getPoints(points1, "first");
    while (checkOnOneLine(points1)){
        std::cout << "The points of the first quadrangle are on one line. Please input again.\n";
        getPoints(points1, "first");
    }

    getPoints(points2, "second");
    while (checkOnOneLine(points2)){
        std::cout << "The points of the second quadrangle are on one line. Please input again.\n";
        getPoints(points2, "second");
    }
}

bool geometry::checkOnOneLine(std::vector<Point>& points){
    double area1 = triangle::triangleArea({points[0], points[1], points[2]}),
           area2 = triangle::triangleArea({points[0], points[1], points[3]}),
           area3 = triangle::triangleArea({points[1], points[2], points[3]}),
           area4 = triangle::triangleArea({points[0], points[2], points[3]});

    return (area1 == 0 || area2 == 0 || area3 == 0 || area4 == 0);
}

bool geometry::onSegment(Point A, Point B, Point C) {
    if (B.x <= std::max(A.x, C.x) && B.x >= std::min(A.x, C.x) &&
        B.y <= std::max(A.y, C.y) && B.y >= std::min(A.y, C.y)){
        return true;
    }
    return false;
}

double geometry::crossProduct(Point A, Point B, Point C){
    double crossProd = (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
    return crossProd;
}

int geometry::crossProductSign(geometry::Point A, geometry::Point B, geometry::Point C) {
    if (crossProduct(A, B, C) == 0) return 0;

    return (crossProduct(A, B, C) > 0)? 1:2;
}

bool geometry::doSegmentsIntersect(Point A, Point B, Point C, Point D){
    int cross1 = crossProductSign(A, B, C),
           cross2 = crossProductSign(A, B, D),
           cross3 = crossProductSign(C, D, A),
           cross4 = crossProductSign(C, D, B);

    if ((cross1 != cross2) && (cross3 != cross4)) return true;

    if (cross1 == 0 && onSegment(A, C, B)) return true;
    if (cross2 == 0 && onSegment(A, D, B)) return true;
    if (cross3 == 0 && onSegment(C, A, D)) return true;
    if (cross4 == 0 && onSegment(C, B, D)) return true;

    return false;
}