#include <gtest/gtest.h>
#include <vector>
#include <type_traits>
#include "gs.cpp"

TEST(ParameterTest, ModelParametersType) {
    // Check if the parameter type is double
    EXPECT_TRUE((std::is_same<decltype(F), double>::value));
    EXPECT_TRUE((std::is_same<decltype(k), double>::value));
    
    // Check if the grid vector type is vector<vector<double>>
    typedef std::vector<std::vector<double>> GridType;
    EXPECT_TRUE((std::is_same<decltype(u), GridType>::value));
    EXPECT_TRUE((std::is_same<decltype(v), GridType>::value));
}