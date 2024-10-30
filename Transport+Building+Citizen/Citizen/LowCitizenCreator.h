#ifndef LOWCITIZENCREATOR_H
#define LOWCITIZENCREATOR_H

#include "Creator.h"
#include "Citizen.h"    

class LowCitizenCreator : public Creator{
    public:
        LowCitizenCreator();
        Citizen* citizenMethod();
};
#endif