#include <gtest/gtest.h>
#include "../Structure.h"
#include "../BasicStructure.h"
#include "../Utilities.h"
#include "../WasteUtility.h"
#include "../WaterUtility.h"
#include "../SewageUtility.h"
#include "../PowerUtility.h"

class UtilitiesTest : public ::testing::Test {
protected:
    Structure* structure;
    Utilities* wasteUtility;
    WaterUtility* waterUtility;
    SewageUtility* sewageUtility;
    PowerUtility* powerUtility;

    void SetUp() override {
        BasicStructure* structure = new BasicStructure("CityHall", 'L',100);

        // Create each utility and chain them
        wasteUtility = new WasteUtility(structure);
        waterUtility = new WaterUtility(structure);
        sewageUtility = new SewageUtility(structure);
        powerUtility = new PowerUtility(structure);

        wasteUtility->setNext(waterUtility);
        waterUtility->setNext(sewageUtility);
        sewageUtility->setNext(powerUtility);
    }

    void TearDown() override {
        delete powerUtility;
        delete sewageUtility;
        delete waterUtility;
        delete wasteUtility;
        delete structure;
    }
};

// Test if WasteUtility correctly processes a request containing 'B'
TEST_F(UtilitiesTest, WasteUtilityProcessRequest) {
    structure->setWasteAmount(50); // Set initial waste amount

    wasteUtility->processRequest("B"); // Process request to collect waste

    ASSERT_EQ(structure->getWasteAmount(), 0); // Waste should be reset to 0
}

// Test if WaterUtility correctly processes a request containing 'W'
TEST_F(UtilitiesTest, WaterUtilityProcessRequest) {
    structure->setAvailableWater(0); // Set initial available water
    int initialCapacity = waterUtility->getCapacity();

    waterUtility->processRequest("W"); // Process request to extract water

    ASSERT_EQ(structure->getAvailableWater(), initialCapacity + 100); // Water should be increased
}

// Test if SewageUtility correctly processes a request containing 'S'
TEST_F(UtilitiesTest, SewageUtilityProcessRequest) {
    structure->setSewageAmount(30); // Set initial sewage amount

    sewageUtility->processRequest("S"); // Process request to treat sewage

    ASSERT_EQ(structure->getSewageAmount(), 0); // Sewage should be reset to 0
}

// Test if PowerUtility correctly processes a request containing 'P'
TEST_F(UtilitiesTest, PowerUtilityProcessRequest) {
    structure->setKilowatts(0); // Set initial power in kilowatts
    int initialPower = powerUtility->getPowerMega();

    powerUtility->processRequest("P"); // Process request to generate power

    ASSERT_EQ(structure->getKilowatts(), initialPower + 50); // Power should be increased by 50
}

// Test the complete chain to ensure all handlers are called in sequence
TEST_F(UtilitiesTest, CompleteChainRequestProcess) {
    structure->setWasteAmount(20);
    structure->setAvailableWater(10);
    structure->setSewageAmount(25);
    structure->setKilowatts(5);

    wasteUtility->processRequest("BWSP"); // Trigger all utilities in sequence

    // Validate each utility's effect on the structure
    ASSERT_EQ(structure->getWasteAmount(), 0);         // Waste should be reset
    ASSERT_GT(structure->getAvailableWater(), 10);      // Water should be increased
    ASSERT_EQ(structure->getSewageAmount(), 0);         // Sewage should be reset
    ASSERT_GT(structure->getKilowatts(), 5);            // Power should be increased
}
