#include <gtest/gtest.h>
#include <vector>
#include <type_traits>
#include "gs.cpp"

TEST(ParameterTest, ModelParametersType) {
    // 检查参数类型是否为 double
    EXPECT_TRUE((std::is_same<decltype(F), double>::value));
    EXPECT_TRUE((std::is_same<decltype(k), double>::value));
    
    // 检查网格向量类型是否为 vector<vector<double>>
    typedef std::vector<std::vector<double>> GridType;
    EXPECT_TRUE((std::is_same<decltype(u), GridType>::value));
    EXPECT_TRUE((std::is_same<decltype(v), GridType>::value));
}