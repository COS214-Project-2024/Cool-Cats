#ifndef MAYOR_H
#define MAYOR_H

#include "Citizen.h"
#include "CitizenIterator.h"

#include <iostream>

class Mayor : public Citizen{
    public:
        Mayor();
        void addService(std::string newService);
        void removeService(std::string oldService);
        CitizenIterator* createCitizenIterator();

    private:
        static int MayorCount;
};
#endif