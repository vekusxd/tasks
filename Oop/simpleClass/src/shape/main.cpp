#include "shape.hpp"
#include <iostream>
#include <vector>
#include <memory>


int main(){
    Shape someShape;
    someShape.addPoint(1, 3);
    someShape.addPoint(3, 5);
    someShape.addPoint(45,5);

    std::cout << "Perimeter: " << someShape.getPerimeter() << std::endl;
    std::cout << "Area: " << someShape.getArea() << std::endl;

    std::vector<Shape> shapes;
    std::vector<std::unique_ptr<Shape>> shapePtrs;

    shapePtrs.push_back(std::make_unique<Shape>(Shape()));
    shapePtrs.push_back(std::make_unique<Shape>(Shape()));
    shapePtrs.push_back(std::make_unique<Shape>(Shape()));
    shapePtrs.push_back(std::make_unique<Shape>(Shape()));

    shapePtrs[1]->addPoint(2, 4);
    shapePtrs[1]->addPoint(3, 8);
    shapePtrs[1]->addPoint(4, 9);


    std::cout << "Area from pointer: " << shapePtrs[1]->getArea() << std::endl;


}