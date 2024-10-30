#ifndef HIGHCITIZENCREATOR_H
#define HIGHCITIZENCREATOR_H

#include "Creator.h"
#include "Citizen.h"

class HighCitizenCreator : public Creator{
    public:
        HighCitizenCreator();
        Citizen* citizenMethod();
};
#endif