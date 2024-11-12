#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "gs.cpp"  // Include the original code to access the definitions of u and v

// Helper function to reset u and v to zero
void resetUVZero() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            u[i][j] = 0.0;
            v[i][j] = 0.0;
        }
    }
}

// Test to verify that when u and v are initialized to zero,
// they remain zero after a simulation step.
TEST(SimulationTest, EvolutionEquations_UVZero) {
    resetUVZero();  // Initialize u and v to zero

    simulateStep();  // Perform one time step of the simulation

    // Check if every value in u and v is still zero
    bool allZero = true;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (std::fabs(u[i][j]) > 1e-9 || std::fabs(v[i][j]) > 1e-9) {  // Check floating-point precision
                allZero = false;
                break;
            }
        }
        if (!allZero) break;
    }

    EXPECT_TRUE(allZero) << "When u = 0 and v = 0, the evolution equations should maintain u and v as zero.";
}
