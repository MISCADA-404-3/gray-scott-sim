#include <gtest/gtest.h>
#include <vector>
#include "gs.cpp"

TEST(DimensionTest, UVSameDimensions) {
    // Check if the number of rows in u and v are the same
    EXPECT_EQ(u.size(), v.size()) << "u 和 v 的行数不相同";

    // Check if the number of columns in the first row is the same 
    //(since all rows have the same number of columns when the vector is initialized)
    EXPECT_EQ(u[0].size(), v[0].size()) << "u 和 v 的列数不相同";
}