#ifndef MIDDLECITIZEN_H
#define MIDDLECITIZEN_H

#include "Citizen.h"
#include "CitizenIterator.h"

#include <iostream>

class MiddleCitizen : public Citizen{
     public:
        MiddleCitizen();
        void addService(std::string newService);
        void removeService(std::string oldService);
        CitizenIterator* createCitizenIterator();
    
    private:
        static int middleClassCitizenCount;
};
#endif