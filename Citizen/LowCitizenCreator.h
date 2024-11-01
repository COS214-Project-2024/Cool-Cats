#ifndef LOWCITIZENCREATOR_H
#define LOWCITIZENCREATOR_H

#include <memory>

#include "Creator.h"
#include "Citizen.h"    

class LowCitizenCreator : public Creator{
    public:
        LowCitizenCreator();

    protected:
        Citizen* basicCitizenMethod();
        Citizen* specificCitizenMethod(std::string employmentStatus, double satisfaction, Structure* home) override;
};
#endif