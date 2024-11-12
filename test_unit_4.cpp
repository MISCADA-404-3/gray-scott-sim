#include "gs.cpp"  // 引入主程序文件以访问其变量和函数
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

// 定义runSimulation函数，用于测试时运行模拟并返回结果
double runSimulation(double du, double dv, double feed_rate, double kill_rate, double threshold) {
    // 设置参数
    Du = du;
    Dv = dv;
    F = feed_rate;
    k = kill_rate;
    
    // 初始化网格
    init();

    // 运行固定步数的模拟
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }

    // 计算并返回满足条件的元素比例
    return countElementsAboveThreshold(threshold);
}


// 确定性测试，确保在相同参数下结果一致
// 使用参数化测试进行不同参数集的测试
TEST(SimulationDeterministicTest, ConsistentOutputWithDifferentParametersAndMultipleRuns) {
    // 定义多个测试参数集，每个参数集为 (Du, Dv, F, k, threshold)
    std::vector<std::tuple<double, double, double, double, double>> parameters = {
        {0.14, 0.07, 0.03, 0.0648, 0.1},
        {0.16, 0.08, 0.02, 0.065, 0.15},
        {0.12, 0.06, 0.04, 0.063, 0.2}
    };

    // 遍历每个参数集
    for (const auto& [du, dv, feed_rate, kill_rate, threshold] : parameters) {
        // 基于每个参数集运行多次模拟，并确保每次结果一致
        double baseline_result = runSimulation(du, dv, feed_rate, kill_rate, threshold);

        for (int i = 0; i < 5; ++i) {  // 每个参数集测试5次
            double result = runSimulation(du, dv, feed_rate, kill_rate, threshold);
            ASSERT_NEAR(baseline_result, result, 1e-6) 
                << "Inconsistent result for parameters (Du=" << du 
                << ", Dv=" << dv << ", F=" << feed_rate << ", k=" 
                << kill_rate << ", threshold=" << threshold << ") on run " << i;
        }
    }
}
