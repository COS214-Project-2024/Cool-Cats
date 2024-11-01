#include <gtest/gtest.h>

#include "../Citizen/Citizen.h"
#include "../Citizen/Mayor.h"
#include "../Citizen/HighCitizen.h"

using namespace std;

//Default and parameterized constructor tested in MayorTest
TEST(HighCitizenTest, Vote)
{
    Mayor* m = new Mayor();

    HighCitizen* hc = new HighCitizen();
    hc->vote();

    EXPECT_EQ(m->getVoteCount(), 1);

    delete hc;
    delete m;
}
TEST(HighCitizenTest, NumOfHighCitizens)
{
    HighCitizen *hc = new HighCitizen();

    EXPECT_EQ(HighCitizen::getHighClassCitizenCount(), 1);

    delete hc;
}
TEST(HighCitizenTest, Income)
{
    HighCitizen *hc = new HighCitizen();
    Income* in = hc->getIncome();

    EXPECT_EQ(in->getRange().at(0), 20000);
    EXPECT_EQ(in->getRange().at(1), 1000000);
    EXPECT_EQ(in->getTaxRate(), 3.5);
    EXPECT_EQ(in->getUtilityCharges(), 2.75);

    delete hc;
}
TEST(HighCitizenTest, Deconstructor)
{
    HighCitizen *hc1 = new HighCitizen();
    HighCitizen *hc2 = new HighCitizen();

    EXPECT_EQ(HighCitizen::getHighClassCitizenCount(), 2);

    delete hc2;

    EXPECT_EQ(HighCitizen::getHighClassCitizenCount(), 1);

    delete hc1;
}
