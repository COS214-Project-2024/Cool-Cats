#ifndef MIDDLECITIZEN_H
#define MIDDLECITIZEN_H

#include "Citizen.h"
#include "CitizenIterator.h"
#include "Income.h"
#include "AllCitizenIterator.h"

#include <iostream>

class MiddleCitizen : public Citizen{
     public:
        MiddleCitizen();
        MiddleCitizen(std::string employmentStatus, double satisfaction, Structure* home);
        void vote();
        static int getMiddleClassCitizenCount();
        Income* getIncome();
        AllCitizenIterator* createCitizenIterator();
        ~MiddleCitizen();
    
    private:
        static int middleClassCitizenCount;
        Income* income;
};
#endif