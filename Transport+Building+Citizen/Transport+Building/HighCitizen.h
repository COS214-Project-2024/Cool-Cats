#ifndef HIGHCITIZEN_H
#define HIGHCITIZEN_H

#include "Citizen.h"
#include "CitizenIterator.h"

#include <iostream>

class HighCitizen : public Citizen{
    public:
        HighCitizen();
        void addService(std::string newService);
        void removeService(std::string oldService);
        CitizenIterator* createCitizenIterator();
    
    private:
        static int highClassCitizenCount;
};
#endif