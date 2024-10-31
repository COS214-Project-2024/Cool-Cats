#ifndef MAYOR_H
#define MAYOR_H

#include <memory>

#include "Citizen.h"
#include "CitizenIterator.h"
#include "Income.h"

class Mayor : public Citizen{
    public:
        Mayor();
        Mayor(std::string employmentStatus, double satisfaction, Structure* home, std::string name);
        std::string getMayorName();
        void setMayorName(std::string newName);
        void receiveVote();
        int getVoteCount();
        bool getElectionStatus();
        void setElectionStatus(bool newStatus);
        static int getMayorCount();
        Income* getIncome();
        CitizenIterator* createCitizenIterator();
        ~Mayor();

    private:
        static int MayorCount;
        std::string name;
        int voteCount;
        bool electedMayor;
        Income* income;
};
#endif