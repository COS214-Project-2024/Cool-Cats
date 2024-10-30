#ifndef MAYORCREATOR_H
#define MAYORCREATOR_H

#include "Creator.h"
#include "Citizen.h"

class MayorCreator : public Creator{
    public:
        MayorCreator();
        Citizen* citizenMethod();
};
#endif