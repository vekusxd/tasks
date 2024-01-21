#include <iostream>
#include <cmath>

#include "shape.hpp"

Shape::Point::Point(double x, double y){
    X = x;
    Y = y;
}

void Shape::Point::display(){
    std::cout << this->X << " " << this->Y;
}


void Shape::addPoint(double x, double y){
    Point point(x, y);
    points.emplace_back(point);
    count++;
}

void Shape::popPoint(){
    points.pop_back();
    count--;
}


void Shape::deletePoint(int index){
    if(points.size() > index)
        points.erase(points.begin() + index);
}

void Shape::displayPoints(){
    for(Point& p : points){
        p.display();
        std::cout << std::endl;
    }
}

unsigned Shape::getCount() const { return count; }

double Shape::getArea(){
    if(count < 3 ){
        throw std::runtime_error("Нужно минимум 3 точки!");
    }
    double sum1 = 0;
    double sum2 = 0;
    for(int i = 0; i < count - 1; i++){
        sum1 += points[i].X * points[i + 1].Y;
        sum2 += points[i].Y * points[i + 1].X;
    }
    sum1 += points[count - 1].X * points[0].Y;
    sum2 += points[count - 1].Y * points[0].X;

    return std::abs((sum1 - sum2) / 2);
}

double Shape::getPerimeter(){
    if(count < 3){
        throw std::runtime_error("Нужно минимум 3 точки!");
    }
    double result;

    for(int i = 0; i < count; i++){
        result += sqrt(pow((points[i].X - points[i + 1].X), 2) + pow((points[i].Y - points[i + 1].Y), 2));
    }
    return result;
}

