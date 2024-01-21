#include "simpleFraction.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main(){
    SimpleFraction a1(3, 4);
    SimpleFraction a2(5,6);

    SimpleFraction a3 = a1 * a2;
    SimpleFraction a4 = a1 / a2;

    std::cout << "a1 * a2 = ";
    a3.display();

    std::cout << "\na1 / a2 = ";
    a4.display();

    std::cout << std::endl;

    std::vector<SimpleFraction> fractions;

    std::vector<std::unique_ptr<SimpleFraction>> fractionsPtr;

    fractionsPtr.push_back(std::make_unique<SimpleFraction>(2, 4));
    fractionsPtr.push_back(std::make_unique<SimpleFraction>(3, 5));
    fractionsPtr.push_back(std::make_unique<SimpleFraction>(7, 8));

    SimpleFraction a5 = *fractionsPtr[0] + *fractionsPtr[1];

    a5.display();
}