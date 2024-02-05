#include <regex>
#include <string>
#include <iostream>

int main(){
    std::regex pattern("^\\s*удалить\\s+([^\\u0000-\\u007F]|\\w)+\\s*$");

    std::regex pattern2("^\\s*Удалить\\s+([^\\u0000-\\u007F]|\\w)+\\s*$");


    std::string something = "Удалить слово";
    std::cout << std::regex_match(something, pattern2) << std::endl;
}