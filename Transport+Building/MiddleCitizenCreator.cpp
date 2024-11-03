#include <iostream>
#include <memory>

#include "MiddleCitizenCreator.h"
#include "MiddleCitizen.h"

MiddleCitizenCreator::MiddleCitizenCreator() : Creator() { };

/// @brief Creates a new middle class citizen
/// @return a new middle class citizen object
std::unique_ptr<Citizen> MiddleCitizenCreator::basicCitizenMethod()
{
    return make_unique<MiddleCitizen>();
}
std::unique_ptr<Citizen> MiddleCitizenCreator::specificCitizenMethod(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home)
{
    return make_unique<MiddleCitizen>(employmentStatus, satisfaction, home);
}