#include <httplib.h>
#include <fstream>
#include <sstream>
#include <string>


int main(){
    httplib::Server svr;

    svr.Get("/test", [](const httplib::Request &, httplib::Response& res){
        std::ifstream in("photo.jpeg", std::ios::in | std::ios::binary);
        if(in){
            std::ostringstream contents;
            contents << in.rdbuf();
            in.close();
            res.set_content(contents.str(), "image/jpeg");
        }
        else{
            res.status=404;
        }
    });


    svr.Get("/", [](const httplib::Request &, httplib::Response &res){
        res.set_content(u8"Батманов Эмиль", "text/plain");
    });

    svr.listen("localhost", 8080);
}


