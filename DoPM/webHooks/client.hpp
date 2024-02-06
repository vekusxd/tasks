#pragma once

#include "deps/httplib/httplib.h"
#include "workWithDb.hpp"
#include "deps/nlohmann/json.hpp"

namespace Client{
    inline httplib::Client client("http://127.0.0.1:5000");

    void post(const nlohmann::json& data){
        client.Post("/", data.dump(), "application/json");
    }
}