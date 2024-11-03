#include <iostream>

#include "MiddleCitizenCreator.h"
#include "MiddleCitizen.h"

MiddleCitizenCreator::MiddleCitizenCreator() : Creator() { };

/// @brief Creates a new middle class citizen
/// @return a new middle class citizen object
Citizen* MiddleCitizenCreator::basicCitizenMethod()
{
    return new MiddleCitizen();
}
Citizen* MiddleCitizenCreator::specificCitizenMethod(std::string employmentStatus, double satisfaction, Structure* home)
{
    return new MiddleCitizen(employmentStatus, satisfaction, home);
}