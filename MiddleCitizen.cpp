#include <iostream>
#include <cstdlib>

#include "MiddleCitizen.h"
#include "Mayor.h"
#include "Income.h"
#include "AllCitizenIterator.h"

using namespace std;

int MiddleCitizen::middleClassCitizenCount = 0;

/// @brief Creates a new basic citizen object
MiddleCitizen::MiddleCitizen() : Citizen()
{
    middleClassCitizenCount++;
    income = new Income(10000, 19999, 4.5);
}

/// @brief Creates a new middle-class citizen object
/// @param employmentStatus the employment status of the middle-class citizen, may only be either 'unemployed', 'employed', or 'self-employed' 
/// @param satisfaction the satisfaction of the high-class citizen, may only be between 0-100
/// @param home the home where the middle-class citizen lives
MiddleCitizen::MiddleCitizen(string employmentStatus, double satisfaction, Structure* home) : Citizen(employmentStatus, satisfaction, home)
{
    middleClassCitizenCount++;
    income = new Income(10000, 19999, 4.5);
}

/// @brief Makes a middle-class citizen vote for a random mayor
void MiddleCitizen::vote()
{
    if(Mayor::getMayorCount() <= 0)
    {
        return;
    }
    vector<Mayor*> mayors = Citizen::getMayors();

    if(mayors.empty())
    {
        return;
    }

    int random = rand() % mayors.size();
    mayors[random]->receiveVote();
}

/// @brief Static method that returns the number of active middle-class citizens in the city
/// @return number of middle-class citizens
int MiddleCitizen::getMiddleClassCitizenCount()
{
    return middleClassCitizenCount;
}

/// @brief Returns the income object of the specific middle-class citizen
/// @return the income object of the middle-class citizen
Income* MiddleCitizen::getIncome()
{
    return income;
}

/// @brief Returns an all citizen iterator object that allows a user to iterate through all citizens, regardless of type
/// @return An AllCitizenIterator Object
AllCitizenIterator* MiddleCitizen::createCitizenIterator()
{
    return new AllCitizenIterator(citizens);
}

MiddleCitizen::~MiddleCitizen()
{
    middleClassCitizenCount--;
    delete income;
}
