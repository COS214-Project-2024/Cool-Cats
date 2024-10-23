#ifndef MIDDLECITIZENCREATOR_H
#define MIDDLECITIZENCREATOR_H

#include "Creator.h"
#include "Citizen.h"

class MiddleCitizenCreator : public Creator{
    public:
        MiddleCitizenCreator();
        Citizen* citizenMethod();
};
#endif