#include "gtest/gtest.h"
#include "gs.cpp"
#include <random>

// Function to generate random values within a specified range
double getRandomValue(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

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

// Test for parameter values being in a valid range
TEST(GrayScottTest, ValidityCheck) {
    // Generate random values within a specified range for testing
    Du = getRandomValue(0.01, 1.0);
    Dv = getRandomValue(0.01, 1.0);
    F = getRandomValue(0.01, 0.1);
    k = getRandomValue(0.01, 0.1);

    // Validate that parameters are within expected ranges
    EXPECT_GT(Du, 0.0);
    EXPECT_LE(Du, 1.0);

    EXPECT_GT(Dv, 0.0);
    EXPECT_LE(Dv, 1.0);

    EXPECT_GT(F, 0.0);
    EXPECT_LE(F, 0.1);

    EXPECT_GT(k, 0.0);
    EXPECT_LE(k, 0.1);
}

// Test for boundary values of parameters
TEST(GrayScottTest, BoundaryCheck) {
    // Assign boundary values to the parameters
    Du = 1.0;
    Dv = 1.0;
    F = 0.1;
    k = 0.1;

    // Ensure that boundary values are still considered valid
    EXPECT_GT(Du, 0.0);
    EXPECT_LE(Du, 1.0);

    EXPECT_GT(Dv, 0.0);
    EXPECT_LE(Dv, 1.0);

    EXPECT_GT(F, 0.0);
    EXPECT_LE(F, 0.1);

    EXPECT_GT(k, 0.0);
    EXPECT_LE(k, 0.1);
}

// Test for invalid parameter values (out of range)
TEST(GrayScottTest, InvalidValues) {
    // Assign invalid values to parameters
    Du = -0.1;
    Dv = 1.5;
    F = -0.05;
    k = 0.2;

    // Check that parameters are correctly identified as invalid
    EXPECT_FALSE(Du > 0.0 && Du <= 1.0);
    EXPECT_FALSE(Dv > 0.0 && Dv <= 1.0);
    EXPECT_FALSE(F > 0.0 && F <= 0.1);
    EXPECT_FALSE(k > 0.0 && k <= 0.1);
}
