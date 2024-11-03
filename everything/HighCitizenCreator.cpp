#include <iostream>

#include "HighCitizenCreator.h"
#include "HighCitizen.h"

HighCitizenCreator::HighCitizenCreator() : Creator() { };

/// @brief Creates and returns a new basic high class citizen
/// @return A new high citizen object
Citizen* HighCitizenCreator::basicCitizenMethod()
{
    return new HighCitizen();
}

/// @brief Creates and returns a new specified high class citizen
/// @param employmentStatus The employment status of the citizen, either 'unemployed', 'employed' or 'self-employed' 
/// @param satisfaction The satisfaction the citizen has with the city, between 0-100
/// @param home The assigned home of the citizen
/// @return A new citizen object
Citizen* HighCitizenCreator::specificCitizenMethod(std::string employmentStatus, double satisfaction, Structure* home)
{  
    return new HighCitizen(employmentStatus, satisfaction, home);
}