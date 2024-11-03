#include <iostream>

#include "Creator.h"

using namespace std;

Creator::Creator(){}

/// @brief Creates and returns a new basic citizen object 
/// @return A new citizen that was created
Citizen* Creator::basicCitizenOperation()
{
    return basicCitizenMethod();
}

/// @brief Creates and returns a new specified citizen object
/// @param employmentStatus The employment status of the citizen, either 'unemployed', 'employed' or 'self-employed' 
/// @param satisfaction The satisfaction the citizen has with the city, between 0-100
/// @param home The assigned home of the citizen
/// @return A new citizen object
Citizen* Creator::specificCitizenOperation(string employmentStatus, double satisfaction, Structure* home)
{
    return specificCitizenMethod(employmentStatus, satisfaction, home);
}
Creator::~Creator(){ }