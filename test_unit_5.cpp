#include "gtest/gtest.h"
#include "gs.cpp"
#include <random>

double getRandomValue(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

// Intialization Test
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

// Values In range
TEST(GrayScottTest, ValidityCheck) {
    Du = getRandomValue(0.01, 1.0);
    Dv = getRandomValue(0.01, 1.0);
    F = getRandomValue(0.01, 0.1);
    k = getRandomValue(0.01, 0.1);

    EXPECT_GT(Du, 0.0);
    EXPECT_LE(Du, 1.0);

    EXPECT_GT(Dv, 0.0);
    EXPECT_LE(Dv, 1.0);

    EXPECT_GT(F, 0.0);
    EXPECT_LE(F, 0.1);

    EXPECT_GT(k, 0.0);
    EXPECT_LE(k, 0.1);
}

// Boundary Test
TEST(GrayScottTest, BoundaryCheck) {
    Du = 1.0;
    Dv = 1.0;
    F = 0.1;
    k = 0.1;

    EXPECT_GT(Du, 0.0);
    EXPECT_LE(Du, 1.0);

    EXPECT_GT(Dv, 0.0);
    EXPECT_LE(Dv, 1.0);

    EXPECT_GT(F, 0.0);
    EXPECT_LE(F, 0.1);

    EXPECT_GT(k, 0.0);
    EXPECT_LE(k, 0.1);
}

// Out of range test
TEST(GrayScottTest, InvalidValues) {
    Du = -0.1;
    Dv = 1.5;
    F = -0.05;
    k = 0.2;

    EXPECT_FALSE(Du > 0.0 && Du <= 1.0);
    EXPECT_FALSE(Dv > 0.0 && Dv <= 1.0);
    EXPECT_FALSE(F > 0.0 && F <= 0.1);
    EXPECT_FALSE(k > 0.0 && k <= 0.1);
}
