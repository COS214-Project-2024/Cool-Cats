#include <gtest/gtest.h>
#include "../government/Taxes.h"
#include "../government/TaxMemento.h"

// Helper function to check float equality with a tolerance
bool isClose(float a, float b, float tolerance = 1e-6) {
    return std::abs(a - b) < tolerance;
}

// Test fixture for Taxes class
class TaxesTest : public ::testing::Test {
protected:
    Taxes* tax;
    
    // Set up resources before each test
    void SetUp() override {
        tax = new Taxes(0.15);
    }

    // Clean up resources after each test
    void TearDown() override {
        delete tax;
    }
};

TEST_F(TaxesTest, ConstructorInitializesTaxRate) {
    EXPECT_TRUE(isClose(tax->getTaxRate(), 0.15)) << "Constructor did not initialize tax rate correctly";
}

TEST_F(TaxesTest, SetTaxRateUpdatesTaxRate) {
    tax->setTaxRate(0.20);
    EXPECT_TRUE(isClose(tax->getTaxRate(), 0.20)) << "setTaxRate did not update the tax rate correctly";
}

TEST_F(TaxesTest, CreateMementoSavesCurrentState) {
    TaxMemento* memento = tax->createMemento();
    ASSERT_NE(memento->getState(), nullptr) << "Memento should not be null";
    EXPECT_TRUE(isClose(memento->getState()->getTaxRate(), 0.15)) << "createMemento did not save the correct tax rate";

    delete memento;  // Clean up to avoid memory leaks
}

TEST_F(TaxesTest, ReinstateMementoRestoresTaxRate) {
    tax->setTaxRate(0.25);
    TaxMemento* memento = tax->createMemento();

    tax->setTaxRate(0.30);  // Change tax rate
    tax->reinstateMemento(memento);  // Restore from memento
    EXPECT_TRUE(isClose(tax->getTaxRate(), 0.25)) << "reinstateMemento did not restore the correct tax rate";

    delete memento;  // Clean up to avoid memory leaks
}
