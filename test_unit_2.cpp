#include <gtest/gtest.h>
#include <vector>
#include "gs.cpp"

TEST(gsTest, gs_size_consistency_test) {
    // Check if the number of rows in u and v are the same
    EXPECT_EQ(u.size(), v.size()) << "The number of rows of u and v are not the same";

    // Check if the number of columns in the first row is the same 
    //(since all rows have the same number of columns when the vector is initialized)
    EXPECT_EQ(u[0].size(), v[0].size()) << "The number of columns of u and v are not the same";
}