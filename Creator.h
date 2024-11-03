#ifndef CREATOR_H
#define CREATOR_H

#include <memory>

#include "Citizen.h"

class Creator{
    public:
        Creator();
        Citizen* basicCitizenOperation();
        Citizen* specificCitizenOperation(std::string employmentStatus, double satisfaction, Structure* home);
        virtual ~Creator();

    protected:
        virtual Citizen* basicCitizenMethod() = 0;
        virtual Citizen* specificCitizenMethod(std::string employmentStatus, double satisfaction, Structure* home) = 0;
};
#endif