#pragma once

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <random>
#include <string>
#include <sstream>
#include "deps/nlohmann/json.hpp"

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::array;


int getRandom(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,2);

    return dist(gen);
}

namespace Db{
    inline mongocxx::instance instance{};
    inline mongocxx::uri uri("mongodb://localhost:27017");
    inline mongocxx::client client(uri);
    inline auto db = client["yandex"];
    
    std::string getGreeting(){
        auto collection = db["greetings"];
        mongocxx::options::find opts;
        opts.projection(make_document(kvp("_id", 0)));
        auto cursor = collection.find(make_document(kvp("_id", getRandom())), opts);
        std::stringstream ss;
        for (auto doc : cursor) {
            ss << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed);
        }
        return ss.str();
    }

    void insertSession(const nlohmann::json& json){
        std::string userId = json["session"]["user_id"];
        auto collection = db["sessions"];

        
        std::string lable = json["request"]["nlu"]["tokens"][0];
        std::string price = json["request"]["nlu"]["tokens"][1];

        auto cursor = collection.find(make_document(kvp("_id", userId)));
        std::stringstream ss;
        for (auto doc : cursor) {
            ss << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed);
        }

        if(ss.str().empty()){
            array newArray;
            newArray.append(make_document(kvp(lable, price)));
            auto inserted = collection.insert_one(make_document(kvp("_id", userId), kvp("goods", newArray)));
            auto update_one = collection.update_one(make_document(kvp("_id", userId)), make_document(kvp("$push", make_document(kvp("goods", make_document(kvp("item",  lable), kvp("price", price)))))));
        }
        else{
            auto update_one = collection.update_one(make_document(kvp("_id", userId)), make_document(kvp("$push", make_document(kvp("goods", make_document(kvp("item",  lable), kvp("price", price)))))));
        }   
    }

    void clearSession(const nlohmann::json& json){
        std::string userId = json["session"]["user_id"];
        auto collection = db["sessions"];

        auto cursor = collection.find(make_document(kvp("_id", userId)));
        std::stringstream ss;
        for (auto doc : cursor) {
            ss << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed);
        }

        array newArray; 

        if(ss.str().empty()){
            auto inserted = collection.insert_one(make_document(kvp("_id", userId), kvp("goods", newArray)));
            return;
        }

        auto update_one = collection.replace_one(make_document(kvp("_id", userId)), make_document(kvp("_id", userId), kvp("goods", newArray)));
    }

    std::string getCart(const nlohmann::json& json){
        std::string userId = json["session"]["user_id"];

        auto collection = db["sessions"];

        auto cursor = collection.find(make_document(kvp("_id", userId)));
        std::stringstream ss;
        for (auto doc : cursor) {
            ss << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed);
        }

        auto sessionJson = nlohmann::json::parse(ss);
        std::string result;
        int counter = 0;

        if(sessionJson["goods"][0].is_null()){
            return "Корзина пуста";
        }
        for (auto& x : sessionJson["goods"].items()){
            std::string tmp1 = x.value()["item"];
            std::string tmp2 = x.value()["price"];
            result += tmp1 + ": " + tmp2 + "\n";
            counter += std::stoi(tmp2);
        }

        result += "Итог: " + std::to_string(counter);
        return result;
    }

    std::string getHelpMessage(){
        mongocxx::options::find opts;
        opts.projection(make_document(kvp("_id", 0)));

        auto collection = db["helpMessage"];
        auto cursor = collection.find({}, opts);
        std::stringstream ss;
         for (auto doc : cursor) {
            ss << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed);
        }
        return ss.str();
    }

    std::string getHelpCommand(int id){
        mongocxx::options::find opts;
        opts.projection(make_document(kvp("_id", 0)));

        auto collection = db["helpCommands"];

        auto cursor = collection.find(make_document(kvp("_id", id)), opts);
        std::stringstream ss;
        for (auto doc : cursor) {
            ss << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed);
        }
        return ss.str();
    }
}