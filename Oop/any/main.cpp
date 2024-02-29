#include <iostream>
#include <string>
#include <vector>

#include "any.hpp"


int main(){
    Any a = 6;

    std::cout << a.getValue<int>() << std::endl;

    a.clear();

    a = 6.67;

    std::cout << a.getValue<double>() << std::endl;

    Any b = std::string("fjdfdkfj");

    a = b;

    std::cout << "\n-------------------------------\n\n";

    try{
        std::cout << a.getValue<float>() << std::endl;
    }
    catch(const std::exception& ex){
        std::cout << ex.what() << std::endl;
    }

    std::cout << "\n-------------------------------\n\n\n";

    std::cout << a.getValue<std::string>() << std::endl;

    Any c = std::vector<int> {3,5,6,7,8,13};

    a = std::move(c);

    for(const auto& i : a.getValue<std::vector<int>>()){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}