cmake_minimum_required(VERSION 3.20)
project(protobufTest)


find_package(Protobuf REQUIRED)

PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ex.proto PROTOC_OUT_DIR ${CMAKE_CURRENT_LIST_DIR})

add_executable(read read.cpp ${ProtoSources} ${ProtoHeaders})
add_executable(${PROJECT_NAME}  main.cpp ${ProtoSources} ${ProtoHeaders})

target_link_libraries(${PROJECT_NAME} PRIVATE ${Protobuf_LIBRARIES})
target_link_libraries(read PRIVATE ${Protobuf_LIBRARIES})