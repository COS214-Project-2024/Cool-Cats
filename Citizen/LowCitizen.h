#ifndef LOWCITIZEN_H
#define LOWCITIZEN_H

#include "Citizen.h"
#include "CitizenIterator.h"

#include <iostream>

class LowCitizen : public Citizen{
     public:
        LowCitizen();
        void addService(std::string newService);
        void removeService(std::string oldService);
        CitizenIterator* createCitizenIterator();
    
    private:
        static int lowClassCitizenCount;
};
#endif