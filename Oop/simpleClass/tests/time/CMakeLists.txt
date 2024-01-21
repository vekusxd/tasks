add_executable(time_tests tests.cpp)

target_link_libraries(time_tests PRIVATE forTests time)

add_test(timeTESTS time_tests)

