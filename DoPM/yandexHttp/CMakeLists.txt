cmake_minimum_required(VERSION 3.20)
project(yandexHTTP VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(HEADERS
    include/widget.hpp
    include/askwidget.hpp
    include/httpManager.hpp
    include/geocordObject.hpp

)


set(SOURCES
    src/widget.cpp
    src/main.cpp
    src/askwidget.cpp
    src/httpManager.cpp
    src/geocordObject.cpp
    
)


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

find_package(Qt6 COMPONENTS Widgets Gui Core Network)
find_package(cpr REQUIRED)
find_package(nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE   Qt6::Widgets
                                                Qt6::Core
                                                Qt6::Gui
                                                Qt6::Network
                                                cpr::cpr
                                                nlohmann_json::nlohmann_json
)   