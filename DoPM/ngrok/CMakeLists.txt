cmake_minimum_required(VERSION 3.20)
project(nGrok)

add_executable(${PROJECT_NAME} main.cpp)

find_package(httplib REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE httplib::httplib)