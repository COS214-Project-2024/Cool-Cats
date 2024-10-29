#include <iostream>
#include <memory>

#include "Creator.h"

using namespace std;

Creator::Creator(){}

/// @brief Returns the new citizen being created
/// @return The new citizen that was created
unique_ptr<Citizen> Creator::basicCitizenOperation()
{
    return basicCitizenOperation();
}
unique_ptr<Citizen> Creator::specificCitizenOperation(string employmentStatus, double satisfaction, shared_ptr<Structure> home)
{
    return specificCitizenOperation(employmentStatus, satisfaction, home);
}
Creator::~Creator(){ }