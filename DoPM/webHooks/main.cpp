#include "deps/httplib/httplib.h"
#include <iostream>
#include "deps/inja/inja.hpp"
#include "deps/nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include  "workWithDb.hpp"


int main(){
    inja::Environment env;
    httplib::Server srv;

    srv.Post("/", [&](const httplib::Request& req, httplib::Response& res){
        bsoncxx::v_noabi::document::view_or_value bsonobj = bsoncxx::from_json(req.body);

        auto collection = Db::db["responses"];
        auto insert_one_result = collection.insert_one(bsonobj);

        auto json = nlohmann::json::parse(req.body);
        if(json["session"]["new"]){

            res.set_content(Db::getGreeting(), "text/json;charset=UTF-8");
            
        }
        else{
        std::regex pattern("^\\s*([^\\u0000-\\u007F]|\\w)+\\s\\d+\\s*$");

        std::string command = json["request"]["command"];

        std::cout << command << std::endl;

        if(std::regex_match(command, pattern)){
            std::fstream in("jsonTemplates/template.json", std::ios_base::in);
            auto jsonTemp = nlohmann::json::parse(in);

            std::string lable = json["request"]["nlu"]["tokens"][0];
            jsonTemp["response"]["text"] = "Товар " + lable + " был добавлен";
            Db::insertSession(json);

            res.set_content(jsonTemp.dump(), "text/json;charset=UTF-8");
            } 
        else if(command == "очистить корзину"){
                Db::clearSession(json);
                std::fstream in("jsonTemplates/template.json", std::ios_base::in);
                auto jsonTemp = nlohmann::json::parse(in);

                jsonTemp["response"]["text"] = "Корзина была очищена";
                res.set_content(jsonTemp.dump(), "text/json;charset=UTF-8");   

            }
        else if(command == "показать содержимое корзины"){
            std::fstream in("jsonTemplates/template.json", std::ios_base::in);

            auto jsonTemp = nlohmann::json::parse(in);
            jsonTemp["response"]["text"] = Db::getCart(json);
            //jsonTemp["response"]["text"] = "idk";

            res.set_content(jsonTemp.dump(), "text/json;charset=UTF-8");   
        }
        else{
            std::fstream in("jsonTemplates/template.json", std::ios_base::in);
            auto jsonTemp = nlohmann::json::parse(in);
            
            jsonTemp["response"]["text"] = "Неизвестная команда";
            res.set_content(jsonTemp.dump(), "text/json;charset=UTF-8");   
        }  
        }
            
    });

    //srv.set_mount_point("/", ".");
    
    srv.Get("/stop", [&](const httplib::Request& req, httplib::Response& res){
        srv.stop();
    });
   srv.listen("localhost", 2005);
}