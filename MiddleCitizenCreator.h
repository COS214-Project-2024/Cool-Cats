#ifndef MIDDLECITIZENCREATOR_H
#define MIDDLECITIZENCREATOR_H

#include "Creator.h"
#include "Citizen.h"

class MiddleCitizenCreator : public Creator{
    public:
        MiddleCitizenCreator();
        std::unique_ptr<Citizen> basicCitizenMethod();
        std::unique_ptr<Citizen> specificCitizenMethod(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home);
};
#endif