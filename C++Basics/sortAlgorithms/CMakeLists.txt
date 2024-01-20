cmake_minimum_required(VERSION 3.20)
project(sortAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(insertion insertionsort.cpp)
add_executable(selection selectionsort.cpp)
add_executable(bubble bubblesort.cpp)
add_executable(counting countingsort.cpp)
add_executable(radix radixsort.cpp)