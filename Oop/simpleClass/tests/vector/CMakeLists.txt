add_executable(vectorTests tests.cpp)

target_link_libraries(vectorTests PRIVATE forTests vectorLib)

add_test(vector_tests vectorTests)