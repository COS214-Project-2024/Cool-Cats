#ifndef HIGHCITIZENCREATOR_H
#define HIGHCITIZENCREATOR_H

#include <memory>

#include "Creator.h"
#include "Citizen.h"

class HighCitizenCreator : public Creator{
    public:
        HighCitizenCreator();

    protected:
        Citizen* basicCitizenMethod();
        Citizen* specificCitizenMethod(std::string employmentStatus, double satisfaction, Structure* home);
};
#endif