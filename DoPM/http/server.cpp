#include <crow.h>
#include <string>


int main(){
    crow::SimpleApp app;

    CROW_ROUTE (app, "/") ([](){
        return "Hello world!";
    });

    CROW_ROUTE (app, "/hello/<string>")([](std::string name){
        auto page = crow::mustache::load("name.html");
        crow::mustache::context ctx ({{"person", name}});
        return page.render(ctx);
    });

    CROW_ROUTE (app, "/text")([](){
        return "Some text!";
    });


    app.port(8080).multithreaded().run();
}