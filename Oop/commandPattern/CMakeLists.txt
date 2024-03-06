cmake_minimum_required(VERSION 3.20)
project(commandPattern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMMANDS
    commands/command.hpp
    commands/backspacecommand.hpp commands/backspacecommand.cpp
    commands/shiftleftcommand.hpp commands/shiftleftcommand.cpp
    commands/shiftrightcommand.hpp commands/shiftrightcommand.cpp
    commands/typecommand.hpp commands/typecommand.cpp
    commands/emptycommand.hpp commands/emptycommand.cpp
)

set(EDITOR editor/editor.hpp editor/editor.cpp)

set(CONTROLLER controller/controller.hpp controller/controller.cpp)

add_executable(${PROJECT_NAME} main.cpp ${COMMANDS} ${EDITOR} ${CONTROLLER})