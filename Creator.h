#ifndef CREATOR_H
#define CREATOR_H

#include <memory>

#include "Citizen.h"

class Creator{
    public:
        Creator();
        std::unique_ptr<Citizen> basicCitizenOperation();
        std::unique_ptr<Citizen> specificCitizenOperation(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home);
        ~Creator();

    protected:
        virtual std::unique_ptr<Citizen> basicCitizenMethod() = 0;
        virtual std::unique_ptr<Citizen> specificCitizenMethod(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home) = 0;
};
#endif