cmake_minimum_required(VERSION 3.20)
project(any LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(any INTERFACE any.hpp)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE any)