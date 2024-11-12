#include <gtest/gtest.h>
#include <vector>
#include "gs.cpp"

TEST(DimensionTest, UVSameDimensions) {
    // 检查 u 和 v 的行数是否相同
    EXPECT_EQ(u.size(), v.size()) << "u 和 v 的行数不相同";

    // 检查第一行的列数是否相同（因为vector初始化时所有行的列数都相同）
    EXPECT_EQ(u[0].size(), v[0].size()) << "u 和 v 的列数不相同";
}