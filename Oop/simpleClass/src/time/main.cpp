#include <iostream>
#include <vector>
#include <memory>
#include "time.hpp"

int main(){
    Time time1(23,445,56);
    Time time2(11, 56, 11);

    std::vector<Time> times(10);

    std::vector<std::unique_ptr<Time>> timePtrs;

    timePtrs.push_back(std::make_unique<Time>(23, 121, 8));
    timePtrs.push_back(std::make_unique<Time>(11,100, 12));


    std::cout << "time1 - time2 = " <<time1 - time2 << std::endl;
    std::cout << "time1: " << time1 << std::endl;
    std::cout << "time1 in seconds: " << time1.getAllSeconds() << std::endl;
}