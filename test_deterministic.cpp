#include "gs.cpp"  // 引入主程序文件以访问其变量和函数
#include <gtest/gtest.h>

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
TEST(SimulationDeterministicTest, ConsistentOutput) {
    // 设置一组测试参数
    double du = 0.14;
    double dv = 0.07;
    double feed_rate = 0.03;
    double kill_rate = 0.0648;
    double threshold = 0.1;

    // 运行两次模拟，比较结果
    double result1 = runSimulation(du, dv, feed_rate, kill_rate, threshold);
    double result2 = runSimulation(du, dv, feed_rate, kill_rate, threshold);

    // 验证两次结果在允许误差范围内相同
    ASSERT_NEAR(result1, result2, 1e-6);  // 允许微小浮点误差
}
