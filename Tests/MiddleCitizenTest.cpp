#include <gtest/gtest.h>

#include "../Citizen.h"
#include "../Mayor.h"
#include "../MiddleCitizen.h"

TEST(MiddleCitizenTest, Vote)
{
    Mayor *m = new Mayor();

    MiddleCitizen *mc = new MiddleCitizen();
    mc->vote();

    EXPECT_EQ(m->getVoteCount(), 1);

    delete mc;
    delete m;
}
TEST(MiddleCitizenTest, NumOfMiddleCitizens)
{
    MiddleCitizen *mc = new MiddleCitizen();

    EXPECT_EQ(MiddleCitizen::getMiddleClassCitizenCount(), 1);

    delete mc;
}
TEST(MiddleCitizenTest, Income)
{
    MiddleCitizen *mc = new MiddleCitizen();
    Income *in = mc->getIncome();

    EXPECT_EQ(in->getRange().at(0), 10000);
    EXPECT_EQ(in->getRange().at(1), 19999);
    EXPECT_EQ(in->getTaxRate(), 4.5);

    delete mc;
}
TEST(MiddleCitizenTest, Deconstructor)
{
    MiddleCitizen *mc1 = new MiddleCitizen();
    MiddleCitizen *mc2 = new MiddleCitizen();

    EXPECT_EQ(MiddleCitizen::getMiddleClassCitizenCount(), 2);

    delete mc2;

    EXPECT_EQ(MiddleCitizen::getMiddleClassCitizenCount(), 1);

    delete mc1;
}