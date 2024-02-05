cmake_minimum_required(VERSION 3.20)
project(webHooks VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(nlohmann deps/nlohmann/json.hpp)
set(httplib deps/httplib/httplib.h)
set(inja deps/inja/inja.hpp)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(server ${httplib} ${inja} ${nlohmann} main.cpp workWithDb.hpp)

target_link_libraries(server PRIVATE mongo::mongocxx_shared mongo::bsoncxx_shared)
