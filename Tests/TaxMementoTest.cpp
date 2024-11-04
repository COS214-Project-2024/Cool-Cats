#include <gtest/gtest.h>
#include "../government/Taxes.h"
#include "../government/TaxMemento.h"

// Test fixture for TaxMemento class
class TaxMementoTest : public ::testing::Test {
protected:
    Taxes* taxes;
    TaxMemento* memento;

    // Set up resources before each test
    void SetUp() override {
        taxes = new Taxes(0.15);
        memento = taxes->createMemento();  // Use the Taxes class to create the memento
    }

    // Clean up resources after each test
    void TearDown() override {
        delete taxes;
        delete memento;
    }
};

TEST_F(TaxMementoTest, ConstructorSavesTaxesState) {
    ASSERT_NE(memento->getState(), nullptr) << "Memento's state should not be null after construction";
    EXPECT_FLOAT_EQ(memento->getState()->getTaxRate(), 0.15) << "Memento did not save the correct tax rate from Taxes";
}

TEST_F(TaxMementoTest, DestructorDeletesSavedState) {
    delete memento;  // Explicitly delete memento to check for memory leaks or crashes
    memento = nullptr;
    // If there is no crash or memory error, the test will pass, indicating proper cleanup
}

TEST_F(TaxMementoTest, GetStateReturnsCorrectTaxesState) {
    Taxes* savedState = memento->getState();
    EXPECT_FLOAT_EQ(savedState->getTaxRate(), 0.15) << "getState did not return the correct tax rate";
}

TEST_F(TaxMementoTest, SetStateUpdatesSavedState) {
    Taxes* newTaxes = new Taxes(0.25);
    memento->setState(newTaxes);

    ASSERT_NE(memento->getState(), nullptr) << "State should not be null after setting";
    EXPECT_FLOAT_EQ(memento->getState()->getTaxRate(), 0.25) << "setState did not update to the correct tax rate";

    delete newTaxes;  // Clean up manually created Taxes object
}
