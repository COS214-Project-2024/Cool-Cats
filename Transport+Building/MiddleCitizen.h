#ifndef MIDDLECITIZEN_H
#define MIDDLECITIZEN_H

#include "Citizen.h"
#include "CitizenIterator.h"
#include "Income.h"

#include <iostream>

class MiddleCitizen : public Citizen{
     public:
        MiddleCitizen();
        MiddleCitizen(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home);
        void vote();
        static int getMiddleClassCitizenCount();
        Income* getIncome();
        CitizenIterator* createCitizenIterator();
        ~MiddleCitizen();
    
    private:
        static int middleClassCitizenCount;
        Income* income;
};
#endif