add_executable(simpleFractionTests simpleFraction.cpp)

target_link_libraries(simpleFractionTests PRIVATE simpleFraction forTests)

add_test(fraction_tests simpleFractionTests)


