#include <iostream>
#include <memory>

#include "LowCitizenCreator.h"
#include "LowCitizen.h"

LowCitizenCreator::LowCitizenCreator() : Creator() { };

/// @brief Creates a new low class citizen
/// @return a new Low Citizen object
std::unique_ptr<Citizen> LowCitizenCreator::basicCitizenMethod()
{
    return make_unique<LowCitizen>();
}
std::unique_ptr<Citizen> specificCitizenMethod(std::string employmentStatus, double satisfaction,  std::shared_ptr<Structure> home)
{
    return make_unique<LowCitizen>(employmentStatus, satisfaction, home);
}