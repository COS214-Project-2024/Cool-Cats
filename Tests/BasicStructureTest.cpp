#include <gtest/gtest.h>
#include "../Structure/BasicStructure.h"

class BasicStructureTest : public ::testing::Test {
protected:
    BasicStructure* residentialStructure;
    BasicStructure* commercialStructure;

    void SetUp() override {
        residentialStructure = new BasicStructure("Residential Building", 'R', 100);
        commercialStructure = new BasicStructure("Commercial Building", 'C', 50);
    }

    void TearDown() override {
        delete residentialStructure;
        delete commercialStructure;
    }
};

TEST_F(BasicStructureTest, TestGetName) {
    ASSERT_EQ(residentialStructure->getName(), "Residential Building");
    ASSERT_EQ(commercialStructure->getName(), "Commercial Building");
}

TEST_F(BasicStructureTest, TestGetType) {
    ASSERT_EQ(residentialStructure->getType(), "R");
    ASSERT_EQ(commercialStructure->getType(), "C");
}

TEST_F(BasicStructureTest, TestAddCitizen) {
    residentialStructure->addcitizen(50);
    ASSERT_EQ(residentialStructure->getCitizenSatisfactionImpact(), 100.0); // assuming impact is at max when full
}

TEST_F(BasicStructureTest, TestRemoveCitizen) {
    residentialStructure->addcitizen(50);
    residentialStructure->removeCitizen(30);
    ASSERT_EQ(residentialStructure->getCitizenSatisfactionImpact(), 70.0); // adjust expected value
}
