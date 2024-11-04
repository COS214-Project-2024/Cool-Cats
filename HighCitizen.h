#ifndef HIGHCITIZEN_H
#define HIGHCITIZEN_H

#include "Citizen.h"
#include "CitizenIterator.h"
#include "Income.h"

#include <iostream>

class HighCitizen : public Citizen{
    public:
        HighCitizen();
        HighCitizen(std::string employmentStatus, double satisfaction, Structure* home);
        void vote();
        static int getHighClassCitizenCount();
        Income* getIncome();
        AllCitizenIterator* createCitizenIterator();
        ~HighCitizen();
    
    private:
        static int highClassCitizenCount;
        Income* income;
};
#endif