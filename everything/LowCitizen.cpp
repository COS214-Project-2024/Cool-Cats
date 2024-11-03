#include <iostream>
#include <cstdlib>

#include "LowCitizen.h"
#include "Mayor.h"
#include "Income.h"
#include "AllCitizenIterator.h"

using namespace std;

int LowCitizen::lowClassCitizenCount = 0;

/// @brief Creates a new basic low-class citizen object
LowCitizen::LowCitizen() : Citizen()
{
    lowClassCitizenCount++;
    income = new Income(0, 10000, 2.5);
}

/// @brief Creates a new low-class citizen object
/// @param employmentStatus the employment status of the low-class citizen, may only either 'employed', 'unemployed', or 'self-employed'
/// @param satisfaction the satisfaction of the low-class citizen, may only be between 0-100
/// @param home the home where the low-class citizen lives
LowCitizen::LowCitizen(string employmentStatus, double satisfaction, Structure* home) : Citizen(employmentStatus, satisfaction, home)
{
    lowClassCitizenCount++;
    income = new Income(0, 10000, 2.5);
}

/// @brief Makes a low-class citizen vote for a random mayor
void LowCitizen::vote()
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
    
    int random = rand()% mayors.size();
    mayors[random]->receiveVote();
}
/// @brief Static method that returns the number of active middle-class citizens in the city
/// @return number of middle-class citizens
int LowCitizen::getLowClassCitizenCount()
{
    return lowClassCitizenCount;
}

/// @brief Returns the income object of the specific middle-class citizen
/// @return the income object of the middle-class citizen
Income* LowCitizen::getIncome()
{
    return income;
}

/// @brief Returns an all citizen iterator object that allows a user to iterate through all citizens, regardless of type
/// @return An AllCitizenIterator object
CitizenIterator* LowCitizen::createCitizenIterator()
{
    return new AllCitizenIterator(citizens);
}

LowCitizen::~LowCitizen()
{
    lowClassCitizenCount--;
    delete income;
}