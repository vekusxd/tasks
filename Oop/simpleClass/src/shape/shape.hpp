#pragma once

#include <iostream>
#include <vector>


class Shape{
private:

    struct Point{
    double X;
    double Y;
    Point(double X, double Y);
    void display();
    };

    std::vector<Point> points;
    unsigned count = 0;


public:
    Shape() {}
    void addPoint(double x, double y);
    void popPoint();
    void deletePoint(int index);
    void displayPoints();
    unsigned getCount() const;
    double getArea();
    double getPerimeter();  
};


