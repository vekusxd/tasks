#pragma once
#include <iostream>
#include <array>

class Point{
private:
    double x = 0;
    double y = 0;

public:
    Point();
    Point(double x, double y);
    double getX() const;
    double getY() const;
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    bool operator==(const Point& other) const;
    double operator*(const Point& other);
};


class Vector{
private:
    double x;
    double y;

public:
    Vector(double x1, double y1, double x2, double y2);
    Vector(const Point& point1, const Point& point2);
    Vector(double x, double y);
    Vector();
    double length();
    double getAngle(const Vector& othter);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    Point operator+(const Vector& other);
    Point operator-(const Vector& other);
    Point operator*(int number);
    double operator*(const Vector& other);
    friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
};