add_executable(shapeTests test.cpp)

target_link_libraries(shapeTests PRIVATE shape forTests)

add_test(shape_tests shapeTests)
