#ifndef MAYORCREATOR_H
#define MAYORCREATOR_H

#include <memory>

#include "Creator.h"
#include "Citizen.h"

class MayorCreator : public Creator{
    public:
        MayorCreator();
        std::unique_ptr<Citizen> basicCitizenMethod();
        std::unique_ptr<Citizen> specificCitizenMethod(std::string employmentStatus, double satisfaction,  std::shared_ptr<Structure> home) override;
        std::unique_ptr<Citizen> specificCitizenMethod(std::string employmentStatus, double satisfaction,  std::shared_ptr<Structure> home, std::string name = "");
};
#endif