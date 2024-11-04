#include <gtest/gtest.h>
#include "../government/Government.h"
#include "../government/Taxes.h"
#include "../government/TaxMemento.h"
#include "../government/CityResourceMediator.h"
#include "../Citizen/AllCitizenIterator.h"
#include "../Citizen/Citizen.h"
#include "../Citizen/Income.h"
#include "../Citizen/HighCitizen.h"

// Test fixture for Government class
class GovernmentTest : public ::testing::Test {
protected:
    Government* government;
    CityResourceMediator* mediator;

    void SetUp() override {
        mediator = new CityResourceMediator();
        government = new Government(mediator);  // Pass mediator to the Government constructor
    }

    void TearDown() override {
        delete government;
        //delete mediator;
    }
};

TEST_F(GovernmentTest, ConstructorInitializesBudgetAndTaxRate) {
    EXPECT_FLOAT_EQ(government->getBudget(), 10000.0) << "Constructor did not initialize budget correctly";
    EXPECT_FLOAT_EQ(government->getTax()->getTaxRate(), 0.10) << "Constructor did not initialize tax rate correctly";
}

TEST_F(GovernmentTest, SetTaxRateUpdatesTaxRate) {
    government->setTaxRate(0.15);
    EXPECT_FLOAT_EQ(government->getTax()->getTaxRate(), 0.15) << "setTaxRate did not update tax rate correctly";
}

TEST_F(GovernmentTest, CollectionAddsToBudget) {
    std::vector<Citizen*> citizens;
    citizens.push_back(new HighCitizen ("employed", 0.5, nullptr));  // Adding a citizen with default income setup

    // Set the income range and tax rate for the citizen's income
    Income* income = citizens.back()->getIncome();
    income->setTaxRate(0.10);
    
    AllCitizenIterator iterator(citizens);

    float initialBudget = government->getBudget();
    government->collection(&iterator);

    // Check that budget increased by income * tax rate
    EXPECT_FLOAT_EQ(government->getBudget(), initialBudget + (income->getRange()[1] * 0.10)) << "collection did not add the correct amount to budget";

    // Clean up dynamically allocated citizens
    for (auto& citizen : citizens) {
        delete citizen;
    }
}

TEST_F(GovernmentTest, ImplementPolicyOutputsCorrectMessage) {
    testing::internal::CaptureStdout();
    government->implementPolicy("New Healthcare Policy");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Implementing policy: New Healthcare Policy\n") << "implementPolicy did not output correct message";
}

TEST_F(GovernmentTest, AllocateBudgetReducesBudget) {
    float initialBudget = government->getBudget();
    government->allocateBudget(2000.0);
    EXPECT_FLOAT_EQ(government->getBudget(), initialBudget - 2000.0) << "allocateBudget did not reduce budget correctly";
}

TEST_F(GovernmentTest, AllocateBudgetInsufficientFunds) {
    testing::internal::CaptureStdout();
    government->allocateBudget(20000.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Insufficient budget to allocate.\n") << "allocateBudget did not output correct message when funds are insufficient";
}

TEST_F(GovernmentTest, StoreAndRetrieveMemento) {
    government->setTaxRate(0.15);
    TaxMemento* memento = government->getTax()->createMemento();
    government->storeMemento(memento);

    TaxMemento* retrievedMemento = government->getMemento();
    ASSERT_NE(retrievedMemento, nullptr) << "getMemento returned null instead of a stored memento";
    EXPECT_FLOAT_EQ(retrievedMemento->getState()->getTaxRate(), 0.15) << "getMemento did not return the correct tax rate in memento";
}

TEST_F(GovernmentTest, SetTaxRateWithTaxesObject) {
    Taxes newTax(0.20);
    government->setTaxRate(&newTax);
    EXPECT_FLOAT_EQ(government->getTax()->getTaxRate(), 0.20) << "setTaxRate(Taxes*) did not set the tax rate correctly";
}

// Example test for CityResourceMediator's coordinateResources
TEST_F(GovernmentTest, CoordinateResourcesUpdatesResourcesCorrectly) {
    mediator->coordinateResources("Infrastructure", 100, 200, 300);

    // Test to ensure resources are managed as expected after coordination
    // (Implementation would depend on how CityResourceMediator updates resources internally)
    // For example:
    // EXPECT_FLOAT_EQ(mediator->getMaterialsAvailable(), expectedMaterials);
    // EXPECT_FLOAT_EQ(mediator->getEnergyAvailable(), expectedEnergy);
    // EXPECT_FLOAT_EQ(mediator->getWaterAvailable(), expectedWater);
}
