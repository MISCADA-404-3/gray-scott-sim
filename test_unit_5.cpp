#include "gtest/gtest.h"
#include "gs.cpp"
#include <random>

// Test for initialization of 'u' and 'v' values
TEST(GrayScottTest, InitializationTest) {
    init(); // Call the initialization function
    // Check all 'u' values are initialized to 1.0
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            ASSERT_EQ(u[x][y], 1.0);
            // Check 'v' values are within the expected range
            if (x >= 100 && x <= 200 && y >= 100 && y <= 150) {
                ASSERT_TRUE(v[x][y] >= 0.0 && v[x][y] <= 1.0);
            } else {
                ASSERT_EQ(v[x][y], 0.0);
            }
        }
    }
}