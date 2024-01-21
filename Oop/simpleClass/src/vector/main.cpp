#include <iostream>
#include <vector>
#include "vector.hpp"
#include <memory>

int main(){
    Vector vector1(1, 5);
    Vector vector2(7, 15);

    std::vector<Vector> vectors(10);

    std::vector<std::unique_ptr<Vector>> vectorPtrs;

    vectorPtrs.push_back(std::make_unique<Vector>(1, 16));
    vectorPtrs.push_back(std::make_unique<Vector>(4, 20));

    std::cout << "Vector pointer multiply: "<< *vectorPtrs[1] * *vectorPtrs[0] << std::endl;


    std::cout << "Vector 1 length: " << vector1.length() << std::endl;
    std::cout << "vector1 + vector2 = " <<vector1 + vector2 << std::endl;
}