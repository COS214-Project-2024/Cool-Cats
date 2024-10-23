#ifndef CREATOR_H
#define CREATOR_H

#include "Citizen.h"

class Creator{
    public:
        void citizenOperation();

    protected:
        virtual Citizen* citizenMethod() = 0;

    private:
        Citizen* citizen;
};
#endif