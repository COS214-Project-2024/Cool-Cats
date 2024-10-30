#include <iostream>

#include "HighCitizenCreator.h"
#include "HighCitizen.h"

HighCitizenCreator::HighCitizenCreator() : Creator() { };

/// @brief Creates a new high class citizen
/// @return a new high citizen object
std::unique_ptr<Citizen> HighCitizenCreator::basicCitizenOperation()
{
    return std::make_unique<HighCitizen>();
}

std::unique_ptr<Citizen> specificCitizenOperation(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home)
{  
    return std::make_unique<HighCitizen>(employmentStatus, satisfaction, home);
}