cmake_minimum_required(VERSION 3.20)
project(laba VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)