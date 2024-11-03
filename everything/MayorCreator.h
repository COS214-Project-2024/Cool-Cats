#ifndef MAYORCREATOR_H
#define MAYORCREATOR_H

#include <memory>

#include "Creator.h"
#include "Citizen.h"

class MayorCreator : public Creator{
    public:
        MayorCreator();

        Citizen* specificCitizenOperation(std::string employmentStatus, double satisfaction,  Structure* home, std::string name);

    protected:
        Citizen* basicCitizenMethod();
        Citizen* specificCitizenMethod(std::string employmentStatus, double satisfaction,  Structure* home) override;
};
#endif