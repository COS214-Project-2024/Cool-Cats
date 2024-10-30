#ifndef HIGHCITIZENCREATOR_H
#define HIGHCITIZENCREATOR_H

#include <memory>

#include "Creator.h"
#include "Citizen.h"

class HighCitizenCreator : public Creator{
    public:
        HighCitizenCreator();
        std::unique_ptr<Citizen> basicCitizenOperation();
        std::unique_ptr<Citizen> specificCitizenOperation(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home);
};
#endif