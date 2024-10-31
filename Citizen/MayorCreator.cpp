#include <iostream>

#include "MayorCreator.h"
#include "Mayor.h"

using namespace std;

MayorCreator::MayorCreator() : Creator() { };

/// @brief Creates a new basic Mayor for the city, there may be multiple mayors
/// @return A new Mayor object
Citizen* MayorCreator::basicCitizenMethod()
{
    return new Mayor();
}

//Method needed for inheritance, empty
Citizen* MayorCreator::specificCitizenMethod(std::string employmentStatus, double satisfaction,  Structure* home)
{
    return nullptr;
}

/// @brief Creates and returns a new specified Mayor citizen
/// @param employmentStatus The employment status of the mayor, either 'unemployed', 'employed' or 'self-employed' 
/// @param satisfaction The satisfaction the Mayor has with the city, between 0-100
/// @param home The assigned home of the mayor
/// @param name The name of the mayor
/// @return A new mayor object
Citizen* MayorCreator::specificCitizenOperation(std::string employmentStatus, double satisfaction,  Structure* home, string name)
{
    return new Mayor(employmentStatus, satisfaction, home, name);
}