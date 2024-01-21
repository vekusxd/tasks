#include "vector.hpp"
#include <cmath>

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

Point::Point(){
    this->x = 0;
    this->y = 0;
}

double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

bool Point::operator==(const Point& other) const{
    return this->x == other.x && this->y == other.y;
}

double Point::operator*(const Point& other){
    return this->x * other.x + this->y * other.y;
}

std::ostream& operator<<(std::ostream& os, const Point& point){
    return os << "x: " << point.x << " y: " << point.y;
}


Vector::Vector( double x1, double y1, double x2, double y2){
   this->x = x2 - x1;
   this->y = y2 - y1;
}

Vector::Vector(const Point& point1,const Point& point2 ){
    this->x = point2.getX() - point1.getX();
    this->y = point2.getY() - point1.getY();
}

Vector::Vector(double x, double y){
    this->x = x;
    this->y = y;
}

Vector::Vector(){
    x = 0;
    y = 0;
}

double Vector::getX() const{
    return x;
}

double Vector::getY() const{
    return y;
}

void Vector::setX(double x){
    this->x = x;
}

void Vector::setY(double y){
    this->y = y;
}

double Vector::length(){
   return sqrt(pow(x, 2) + pow(y, 2));
}

Point Vector::operator*(int number){
    return Point(x * number, y * number);
}

double Vector::operator*(const Vector& other){
    return x * other.x + y * other.y;
}

Point Vector::operator+(const Vector& other){
    return Point(x + other.x, y + other.y);
}

Point Vector::operator-(const Vector& other){
    return Point(x - other.x, y - other.y);
}

double Vector::getAngle(const Vector& other){

    double module1 = sqrt(pow(x,2) + pow(y, 2));
    double module2 = sqrt(pow(other.x,2) + pow(other.y, 2));

    return ((*this * other) /  (module1 * module2));
}

std::ostream& operator<<(std::ostream& out, const Vector& vector){
    return out << "x: " <<vector.x << " y: " << vector.y;
}










