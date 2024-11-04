#include "CityResourceMediator.h"
#include "Government.h"
#include <gtest/gtest.h>

class CityResourceMediatorTest : public ::testing::Test {
protected:
    CityResourceMediator mediator;
    Government government;

    CityResourceMediatorTest() : government(&mediator) {}

TEST_F(CityResourceMediatorTest, CoordinateWaterUsage) {
    mediator.supplyResource(&government, "Water", 100);
    testing::internal::CaptureStdout();
    mediator.coordinateWaterUsage(50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Coordinated water usage: 50. Water available: 50\n");
}

TEST_F(CityResourceMediatorTest, CoordinateEnergyDistribution) {
    mediator.supplyResource(&government, "Energy", 100);
    testing::internal::CaptureStdout();
    mediator.coordinateEnergyDistribution(50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Coordinated energy distribution: 50. Energy available: 50\n");
}

TEST_F(CityResourceMediatorTest, CoordinateMaterialUsage) {
    mediator.supplyResource(&government, "Materials", 100);
    testing::internal::CaptureStdout();
    mediator.coordinateMaterialUsage(50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Coordinated material usage: 50. Materials available: 50\n");
}

TEST_F(CityResourceMediatorTest, ManageBudget) {
    mediator.supplyResource(&government, "Budget", 100);
    testing::internal::CaptureStdout();
    mediator.manageBudget(50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Managed budget: 50. Budget remaining: 50\n");
}

TEST_F(CityResourceMediatorTest, RequestResource) {
    mediator.supplyResource(&government, "Water", 100);
    testing::internal::CaptureStdout();
    mediator.requestResource(&government, "Water", 50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Coordinated water usage: 50. Water available: 50\n");
}

TEST_F(CityResourceMediatorTest, SupplyResource) {
    testing::internal::CaptureStdout();
    mediator.supplyResource(&government, "Water", 100);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Supplied water: 100. Water available: 100\n");
}

TEST_F(CityResourceMediatorTest, CoordinateResources) {
    mediator.supplyResource(&government, "Materials", 100);
    mediator.supplyResource(&government, "Energy", 100);
    mediator.supplyResource(&government, "Water", 100);
    testing::internal::CaptureStdout();
    mediator.coordinateResources("Project", 50, 50, 50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Coordinating resources for project: Project\nCoordinated material usage: 50. Materials available: 50\nCoordinated energy distribution: 50. Energy available: 50\nCoordinated water usage: 50. Water available: 50\n");
}