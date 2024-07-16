#pragma once
#include <vector>
namespace geometry{
    struct Point{
        double x, y;

        bool operator<(const Point& other) const {
            return x < other.x || (x == other.x && y < other.y);
        }
    };
    void getPoints(std::vector<Point>& points1, const std::string& order);
    void getAllPoints(std::vector<Point>& points1, std::vector<Point>& points2);
    bool checkOnOneLine(std::vector<Point>& points);
    bool onSegment(Point A, Point B, Point C);
    double crossProduct(Point A, Point B, Point C);
    int crossProductSign(Point A, Point B, Point C);
    bool doSegmentsIntersect(Point A, Point B, Point C, Point D);
}