#include "gtest/gtest.h"
#include "gs.cpp"

TEST(GrayScottTest, InitializationTest) {
    init();
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            ASSERT_EQ(u[x][y], 1.0);
            if (x >= 100 && x <= 200 && y >= 100 && y <= 150) {
                ASSERT_TRUE(v[x][y] >= 0.0 && v[x][y] <= 1.0);
            } else {
                ASSERT_EQ(v[x][y], 0.0);
            }
        }
    }
}
