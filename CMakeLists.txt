cmake_minimum_required(VERSION 3.10)
project(MySimulationProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加 Googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# 添加主程序
add_executable(MySimulation gs.cpp)

# 添加测试目标
add_executable(SimulationTests test_deterministic.cpp)

# 链接 Googletest 库
target_link_libraries(SimulationTests gtest_main)
target_include_directories(SimulationTests PRIVATE ${gtest_SOURCE_DIR}/include)

# 定义测试
add_test(NAME DeterministicTest COMMAND SimulationTests)
