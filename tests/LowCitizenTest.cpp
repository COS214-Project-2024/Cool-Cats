#include <gtest/gtest.h>

#include "../Citizen/Citizen.h"
#include "../Citizen/Mayor.h"
#include "../Citizen/LowCitizen.h"

//Default and parameterized constructor tested in MayorTest
TEST(LowCitizenTest, Vote)
{
    Mayor *m = new Mayor();

    LowCitizen *lc = new LowCitizen();
    lc->vote();

    EXPECT_EQ(m->getVoteCount(), 1);

    delete lc;
    delete m;
}
TEST(LowCitizenTest, NumOfLowCitizens)
{
    LowCitizen *lc = new LowCitizen();

    EXPECT_EQ(LowCitizen::getLowClassCitizenCount(), 1);

    delete lc;
}
TEST(LowCitizenTest, Income)
{
    LowCitizen *lc = new LowCitizen();
    Income *in = lc->getIncome();

    EXPECT_EQ(in->getRange().at(0), 0);
    EXPECT_EQ(in->getRange().at(1), 10000);
    EXPECT_EQ(in->getTaxRate(), 2.5);

    delete lc;
}
TEST(LowCitizenTest, Deconstructor)
{
    LowCitizen *lc1 = new LowCitizen();
    LowCitizen *lc2 = new LowCitizen();

    EXPECT_EQ(LowCitizen::getLowClassCitizenCount(), 2);

    delete lc1;

    EXPECT_EQ(LowCitizen::getLowClassCitizenCount(), 1);

    delete lc2;
}