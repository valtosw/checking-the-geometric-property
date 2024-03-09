#pragma once
#include <vector>
namespace geometry{
    struct Point{
        double x, y;

        bool operator<(const Point& other) const {
            return x < other.x || (x == other.x && y < other.y);
        }
    };
    void getFirstPoints(std::vector<Point>& points1);
    void getSecondPoints(std::vector<Point>& points2);
    void getAllPoints(std::vector<Point>& points1, std::vector<Point>& points2);
    double area(Point A, Point B, Point C);
    bool checkOnOneLine(std::vector<Point>& points);
    bool onSegment(Point A, Point B, Point C);
    double crossProduct(Point A, Point B, Point C);
    bool doSegmentsIntersect(Point A, Point B, Point C, Point D);
}