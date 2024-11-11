cmake_minimum_required(VERSION 3.10)
project(gray-scott-sim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(gray-scott-sim gs.cpp)

add_executable(test_unit_1 test_unit_1.cpp)
add_executable(test_unit_2 test_unit_2.cpp)
add_executable(test_unit_3 test_unit_3.cpp)
add_executable(test_unit_4 test_unit_4.cpp)
add_executable(test_unit_5 test_unit_5.cpp)

target_link_libraries(test_unit_1 gtest_main)
target_link_libraries(test_unit_2 gtest_main)
target_link_libraries(test_unit_3 gtest_main)
target_link_libraries(test_unit_4 gtest_main)
target_link_libraries(test_unit_5 gtest_main)

target_include_directories(test_unit_1 PRIVATE ${gtest_SOURCE_DIR}/include)
target_include_directories(test_unit_2 PRIVATE ${gtest_SOURCE_DIR}/include)
target_include_directories(test_unit_3 PRIVATE ${gtest_SOURCE_DIR}/include)
target_include_directories(test_unit_4 PRIVATE ${gtest_SOURCE_DIR}/include)
target_include_directories(test_unit_5 PRIVATE ${gtest_SOURCE_DIR}/include)

add_test(NAME UnitTest1 COMMAND test_unit_1)
add_test(NAME UnitTest2 COMMAND test_unit_2)
add_test(NAME UnitTest3 COMMAND test_unit_3)
add_test(NAME UnitTest4 COMMAND test_unit_4)
add_test(NAME UnitTest5 COMMAND test_unit_5)