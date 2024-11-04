#include <gtest/gtest.h>

#include "../Citizen.h"
#include "../Mayor.h"
#include "../HighCitizen.h"
#include "../MiddleCitizen.h"
#include "../LowCitizen.h"

using namespace std;

// Test for default constructor
TEST(MayorTest, DefaultConstructor) {
    Mayor *mayor = new Mayor();
    
    EXPECT_EQ(mayor->getEmploymentStatus(), "Unemployed");
    EXPECT_EQ(mayor->getSatisfaction(), 50);
    EXPECT_EQ(mayor->getHome(), nullptr);

    delete mayor;
}

// Test for parameterized constructor with valid inputs
TEST(MayorTest, ParameterizedConstructorValidInput) {
    Mayor *mayor = new Mayor("employed", 80, nullptr, "Big Boy Mayor");

    EXPECT_EQ(mayor->getEmploymentStatus(), "employed");
    EXPECT_EQ(mayor->getSatisfaction(), 80);
    EXPECT_EQ(mayor->getHome(), nullptr);
    EXPECT_EQ(mayor->getMayorName(), "Big Boy Mayor");
    
    delete mayor;
}

// Test for parameterized constructor with invalid satisfaction
TEST(CitizenTest, ParameterizedConstructorInvalidSatisfaction) {
    Mayor *mayor = new Mayor("ergergerg", 150, nullptr, "\nkrerg_ger");

    EXPECT_EQ(mayor->getEmploymentStatus(), " ");
    EXPECT_EQ(mayor->getSatisfaction(), 50);
    EXPECT_EQ(mayor->getMayorName(), "Mayor 1");

    delete mayor;
}

// Test addService with valid input
TEST(CitizenTest, AddValidService) {
    Mayor *mayor = new Mayor();
    mayor->addService("Housekeeping");
    
    EXPECT_EQ(mayor->getServices().size(), 1);
    EXPECT_EQ(mayor->getServices().at(0), "Housekeeping");

    delete mayor;
}

// Test addService with invalid input
TEST(CitizenTest, AddInvalidService) {
    Mayor *mayor = new Mayor();
    mayor->addService("Invalid@Service");
    
    EXPECT_TRUE(mayor->getServices().empty());

    delete mayor;
}

// Test removeService with existing service
TEST(CitizenTest, RemoveExistingService) {
    Mayor* mayor = new Mayor();
    mayor->addService("Housekeeping");
    mayor->removeService("Housekeeping");

    EXPECT_TRUE(mayor->getServices().empty());

    delete mayor;
}

// Test setEmploymentStatus with valid input
TEST(CitizenTest, SetEmploymentStatusValid) {
    Mayor *mayor = new Mayor();
    mayor->setEmploymentStatus("self-employed");

    EXPECT_EQ(mayor->getEmploymentStatus(), "self-employed");

    delete mayor;
}

// Test setEmploymentStatus with invalid input
TEST(CitizenTest, SetEmploymentStatusInvalid) {
    Mayor* mayor = new Mayor();
    mayor->setEmploymentStatus("invalid-status");

    EXPECT_EQ(mayor->getEmploymentStatus(), "Unemployed");  // Remains as default

    delete mayor;
}

// Test setSatisfaction with valid input
TEST(CitizenTest, SetSatisfactionValid) {
    Mayor *mayor = new Mayor();
    mayor->setSatisfaction(75);

    EXPECT_EQ(mayor->getSatisfaction(), 75);

    delete mayor;
}

// Test setSatisfaction with invalid input
TEST(CitizenTest, SetSatisfactionInvalid) {
    Mayor *mayor = new Mayor();
    mayor->setSatisfaction(150);

    EXPECT_EQ(mayor->getSatisfaction(), 50);  // Unchanged due to invalid input

    delete mayor;
}

// Test determineMayor
TEST(CitizenTest, DetermineMayor) {
    Mayor* mayor1 = new Mayor();
    mayor1->receiveVote();
    mayor1->receiveVote();
    mayor1->receiveVote();
    mayor1->receiveVote();
    mayor1->receiveVote();

    EXPECT_EQ(mayor1->getVoteCount(), 5);

    Mayor* mayor2 = new Mayor();
    mayor2->receiveVote();
    mayor2->receiveVote();
    mayor2->receiveVote();

    EXPECT_EQ(mayor2->getVoteCount(), 3);

    Citizen::determineMayor();
    EXPECT_TRUE(mayor1->getElectionStatus());
    EXPECT_FALSE(mayor2->getElectionStatus());

    delete mayor1;
    delete mayor2;
}

TEST(MayorTest, NumberOfMayors)
{
    Mayor *m1 = new Mayor();
    Mayor *m2 = new Mayor();
    Mayor *m3 = new Mayor();

    EXPECT_EQ(Mayor::getMayorCount(), 3);

    delete m1;
    delete m2;
    delete m3;
}
TEST(MayorTest, GetIncome)
{
    Mayor *m1 = new Mayor();
    Income *income = m1->getIncome();

    EXPECT_EQ(income->getRange().at(0), 10000);
    EXPECT_EQ(income->getRange().at(1), 15000);
    EXPECT_EQ(income->getTaxRate(), 5.5);
    
    delete m1;
}
TEST(MayorTest, TestPopulation)
{
    Mayor *m1 = new Mayor();
    HighCitizen *h1 = new HighCitizen();
    MiddleCitizen *md1 = new MiddleCitizen();
    LowCitizen *l1 = new LowCitizen();

    EXPECT_EQ(Citizen::getPopulationCount(), 4);

    delete l1;
    delete md1;
    delete h1;
    delete m1;
}