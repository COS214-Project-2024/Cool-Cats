#ifndef LOWCITIZEN_H
#define LOWCITIZEN_H

#include "Citizen.h"
#include "CitizenIterator.h"
#include "Income.h"
#include "AllCitizenIterator.h"  


#include <iostream>

class LowCitizen : public Citizen{
     public:
        LowCitizen();
        LowCitizen(std::string employmentStatus, double satisfaction, Structure* home);
        void vote();
        static int getLowClassCitizenCount();
        Income* getIncome();
        AllCitizenIterator* createCitizenIterator();
        ~LowCitizen();
    
    private:
        static int lowClassCitizenCount;
        Income* income;
};
#endif