#include <gtest/gtest.h>
#include "../Citizen.h"
#include "../MayorIterator.h"
#include "../Mayor.h"
#include "../HighCitizen.h"
#include "../MiddleCitizen.h"
#include "../LowCitizen.h"

class MayorIteratorTest : public ::testing::Test{
    protected:
        Mayor* m1 = new Mayor();
        Mayor* m2 = new Mayor();
        Mayor* m3 = new Mayor();
        Mayor* m4 = new Mayor();
        Mayor* m5 = new Mayor();
        Mayor* m6 = new Mayor();
        Mayor* m7 = new Mayor();
        Mayor* m8 = new Mayor();
        Mayor* m9 = new Mayor();
        Mayor* m10 = new Mayor();
        Mayor* m11 = new Mayor();
        Mayor* m12 = new Mayor();
        Mayor* m13 = new Mayor();
        Mayor* m14 = new Mayor();
        Mayor* m15 = new Mayor();

    ~MayorIteratorTest()
    {
        delete m15;
        delete m14;
        delete m13;
        delete m12;
        delete m11;
        delete m10;
        delete m9;
        delete m8;
        delete m7;
        delete m6;
        delete m5;
        delete m4;
        delete m3;
        delete m2;
        delete m1;
    }
};
TEST_F(MayorIteratorTest, IterateAllTest)
{
    CitizenIterator* iterate = m1->createCitizenIterator();

    ASSERT_EQ(iterate->currentItem(), m1);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m2);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m3);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m4);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m5);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m6);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m7);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m8);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m9);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m10);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m11);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m12);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m13);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m14);
    iterate->next();

    ASSERT_EQ(iterate->currentItem(), m15);
    iterate->next();

    ASSERT_TRUE(iterate->isDone());

    delete iterate;
}
TEST_F(MayorIteratorTest, testFirst)
{
    CitizenIterator* iterate = m5->createCitizenIterator();

    iterate->next();
    iterate->next();
    iterate->next();
    iterate->next();
    iterate->next();
    iterate->next();

    iterate->first();
    ASSERT_EQ(iterate->currentItem(), m1);

    delete iterate;
}
