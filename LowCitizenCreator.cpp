#include <iostream>
#include <memory>

#include "LowCitizenCreator.h"
#include "LowCitizen.h"

LowCitizenCreator::LowCitizenCreator() : Creator() { };

/// @brief Creates a new low-class citizen
/// @return a new Low Citizen object
std::unique_ptr<Citizen> LowCitizenCreator::basicCitizenMethod()
{
    return make_unique<LowCitizen>();
}
/// @brief Createas a new specific low-class citizen
/// @param employmentStatus the employment status of the low-class citizen
/// @param satisfaction The satisfaction level of the low-class citizen
/// @param home The home where the low-class citizen lives
/// @return A new low class citizen object
std::unique_ptr<Citizen> LowCitizenCreator::specificCitizenMethod(std::string employmentStatus, double satisfaction,  std::shared_ptr<Structure> home)
{
    return make_unique<LowCitizen>(employmentStatus, satisfaction, home);
}