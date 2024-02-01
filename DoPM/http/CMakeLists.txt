cmake_minimum_required(VERSION 3.20)
project(CLientServer VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(client client.cpp)
add_executable(server server.cpp)

find_package(httplib COMPONENTS OpenSSL ZLIB Brotli)
find_package(fmt REQUIRED)
find_package(Crow)

target_link_libraries(client PRIVATE httplib::httplib)
target_link_libraries(server PRIVATE Crow::Crow)