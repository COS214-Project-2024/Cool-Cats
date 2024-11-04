#include <gtest/gtest.h>
#include "../Structure/StructureGroup.h"
#include "../Structure/BasicStructure.h"

class StructureGroupTest : public ::testing::Test {
protected:
    StructureGroup* group;
    BasicStructure* residentialStructure;
    BasicStructure* commercialStructure;

    void SetUp() override {
        group = new StructureGroup("City Block");
        residentialStructure = new BasicStructure("Residential Building", 'R', 100);
        commercialStructure = new BasicStructure("Commercial Building", 'C', 50);
    }

    void TearDown() override {
        delete group;
        delete residentialStructure;
        delete commercialStructure;
    }
};

TEST_F(StructureGroupTest, TestAddStructure) {
    group->add(residentialStructure);
    ASSERT_EQ(group->getChildren().size(), 1);
}

TEST_F(StructureGroupTest, TestRemoveStructure) {
    group->add(commercialStructure);
    group->remove(commercialStructure);
    ASSERT_EQ(group->getChildren().size(), 0);
}

TEST_F(StructureGroupTest, TestGetMaintenance) {
    group->add(residentialStructure);
    ASSERT_GT(group->getMaintenance(), 0); // expecting some maintenance cost
}

TEST_F(StructureGroupTest, TestGetResourceConsumption) {
    group->add(residentialStructure);
    ASSERT_GT(group->getResourceConsumption(), 0); // expecting some resource consumption
}

TEST_F(StructureGroupTest, TestCitizenSatisfactionImpact) {
    group->add(residentialStructure);
    ASSERT_EQ(group->getCitizenSatisfactionImpact(), 100.0); // expecting max satisfaction
}
