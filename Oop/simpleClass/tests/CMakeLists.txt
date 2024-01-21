add_library(forTests INTERFACE)

find_package(GTest REQUIRED)
target_link_libraries(forTests INTERFACE GTest::GTest)

add_subdirectory(shape)
add_subdirectory(simpleFraction)
add_subdirectory(vector)
add_subdirectory(time)
