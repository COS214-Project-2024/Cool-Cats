#ifndef LOWCITIZENCREATOR_H
#define LOWCITIZENCREATOR_H

#include <memory>

#include "Creator.h"
#include "Citizen.h"    

class LowCitizenCreator : public Creator{
    public:
        LowCitizenCreator();
        std::unique_ptr<Citizen> basicCitizenMethod();
        std::unique_ptr<Citizen> specificCitizenMethod(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home) override;
};
#endif