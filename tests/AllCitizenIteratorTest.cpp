#include <gtest/gtest.h>
#include "../Citizen/Citizen.h"
#include "../Citizen/AllCitizenIterator.h"
#include "../Citizen/Mayor.h"
#include "../Citizen/HighCitizen.h"
#include "../Citizen/MiddleCitizen.h"
#include "../Citizen/LowCitizen.h"

class CitizenIteratorTest : public ::testing::Test {
    protected:
        LowCitizen *lowCitizen1 = new LowCitizen("employed", 75, nullptr);
        LowCitizen *lowCitizen2 = new LowCitizen("umemployed", 50, nullptr);
        LowCitizen *lowCitizen3 = new LowCitizen("self-employed", 85, nullptr);
        MiddleCitizen *middleCitizen1 = new MiddleCitizen("employed", 25, nullptr);
        MiddleCitizen *middleCitizen2 = new MiddleCitizen("umemployed", 35, nullptr);
        MiddleCitizen *middleCitizen3 = new MiddleCitizen("self-employed", 40, nullptr);
        HighCitizen *highCitizen1 = new HighCitizen("employed", 60, nullptr);
        HighCitizen *highCitizen2 = new HighCitizen("umemployed", 62, nullptr);
        HighCitizen *highCitizen3 = new HighCitizen("self-employed", 99, nullptr);

        ~CitizenIteratorTest()
        {
            delete highCitizen3;
            delete highCitizen2;
            delete highCitizen1;
            delete middleCitizen3;
            delete middleCitizen2;
            delete middleCitizen1;
            delete lowCitizen3;
            delete lowCitizen2;
            delete lowCitizen1;
        }
};

TEST_F(CitizenIteratorTest, IterateAllTest)
{
    CitizenIterator* iterate = lowCitizen1->createCitizenIterator();

    ASSERT_EQ(iterate->currentItem(), lowCitizen1);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), lowCitizen2);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), lowCitizen3);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), middleCitizen1);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), middleCitizen2);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), middleCitizen3);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), highCitizen1);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), highCitizen2);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), highCitizen3);
    iterate->next();

    ASSERT_TRUE(iterate->isDone());

    iterate->first();

    while(!iterate->isDone())
    {
        iterate->next();
    }
    ASSERT_TRUE(iterate->isDone());

    delete iterate;
}
TEST_F(CitizenIteratorTest, testFirst)
{
    CitizenIterator *iterate = middleCitizen1->createCitizenIterator();

    iterate->next();
    iterate->next();
    iterate->next();

    iterate->first();
    ASSERT_EQ(iterate->currentItem(), lowCitizen1);

    delete iterate;
}
TEST_F(CitizenIteratorTest, testHigh)
{
    CitizenIterator* iterate = highCitizen1->createCitizenIterator();

    ASSERT_EQ(iterate->currentItem(), lowCitizen1);

    delete iterate;
}