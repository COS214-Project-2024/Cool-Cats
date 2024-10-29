#include <iostream>
#include <memory>

#include "MayorCreator.h"
#include "Mayor.h"

using namespace std;

MayorCreator::MayorCreator() : Creator() { };

/// @brief Creates a new Mayor for the city, there may be multiple mayors
/// @return A new Mayor object
unique_ptr<Citizen> MayorCreator::basicCitizenMethod()
{
    return make_unique<Mayor>();
}
unique_ptr<Citizen> MayorCreator::specificCitizenMethod(std::string employmentStatus, double satisfaction,  std::shared_ptr<Structure> home, string name)
{
    return make_unique<Mayor>(employmentStatus, satisfaction, home, name);
}