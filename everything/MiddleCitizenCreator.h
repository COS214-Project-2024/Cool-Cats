#ifndef MIDDLECITIZENCREATOR_H
#define MIDDLECITIZENCREATOR_H

#include "Creator.h"
#include "Citizen.h"

class MiddleCitizenCreator : public Creator{
    public:
        MiddleCitizenCreator();

    protected:
        Citizen* basicCitizenMethod();
        Citizen* specificCitizenMethod(std::string employmentStatus, double satisfaction, Structure* home);
};
#endif