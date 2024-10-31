#include <iostream>
#include <vector>
#include <cstdlib>

#include "HighCitizen.h"
#include "Mayor.h"
#include "AllCitizenIterator.h"

using namespace std;

int HighCitizen::highClassCitizenCount = 0;

/// @brief Creates a new basic citizen object
HighCitizen::HighCitizen() : Citizen()
{
    highClassCitizenCount++;
    income = new Income(20000, 1000000, 3.5, 2.75);
}

/// @brief Creates a new high-class citizen object
/// @param employmentStatus the employment status of the high-class citizen, may only be either 'unemployed', 'employed' or 'self-employed'
/// @param satisfaction the satisfaction of the high-class citizen, may only be between 0-100
/// @param home the home where the high-class citizen lives
HighCitizen::HighCitizen(string employmentStatus, double satisfaction, Structure* home) : Citizen(employmentStatus, satisfaction, home)
{
    highClassCitizenCount++;
    income = new Income(20000, 1000000, 3.5, 2.75);
}

/// @brief Makes a high-class citizen vote for a random mayor
void HighCitizen::vote()
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

/// @brief Static method that returns the number of active high class citizens in the city
/// @return number of high class citizens
int HighCitizen::getHighClassCitizenCount()
{
    return highClassCitizenCount;
}

/// @brief Returns the income object of the specific high-class citizen
/// @return the income object of the high-class citizen
Income* HighCitizen::getIncome()
{
    return income;
}


/// @brief Returns an all citizen iterator object that allows a user to iterate through all citizens, regardless of type
/// @return An AllCitizenIterator object
CitizenIterator* HighCitizen::createCitizenIterator()
{
    return new AllCitizenIterator(citizens);
}

HighCitizen::~HighCitizen()
{
    highClassCitizenCount--;
    delete income;
}