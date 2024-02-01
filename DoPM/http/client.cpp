#include <httplib.h>
#include <iostream>
#include <fstream>

int main(){
    httplib::Client cli("localhost:8080");


int choice;

while(true){
    std::cin >> choice;
    std::string name;
    switch(choice){
        case 1:
        {
            auto res = cli.Get("/");
            std::cout << res->status << std::endl;
            std::cout << res->body << std::endl;
            break;
        }
        case 2:
        {
            auto res = cli.Get("/text");
            std::cout << res->status << std::endl;
            std::cout << res->body << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Введите ваше имя\n";
            std::cin >> name;
            auto res = cli.Get("/hello/" + name);
            std::cout << res->status << std::endl;
            std::cout << res->body << std::endl;
            break;
        }
        case 4:
        {
            return 0;
            break;
        }
        default:
        {
            break;
        }
    }
}
}