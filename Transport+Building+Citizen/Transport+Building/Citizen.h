#ifndef CITIZEN_H
#define CITIZEN_H

#include <list>
#include <vector>
#include "Structure.h"
// #include "PopulationMemento"
#include "CitizenIterator.h"

class Citizen
{
    public:
        Citizen();
        Citizen(std::string employmentStatus, double satisfaction, Structure* home);
        void AddCitizen(Citizen* newCitizen);
        void removeCitizen(Citizen * target);
        virtual void addService(std::string newService) = 0;
        virtual void removeService(std::string oldService) = 0;
        double getSatisfaction();
        void setSatisfaction(double satisfaction);
        std::string getEmploymentStatus();
        void setEmploymentStatus(std::string employment);
        virtual CitizenIterator* createCitizenIterator() = 0;
        // PopulationMemento* createMemento();
        // void setMemento(PopulationMemento* memento);
        
        
    protected:
        std::vector<std::string> services;

    private:
        std::string employmentStatus;
        std::list<Citizen*> citizens;
        Structure* home;
        double satisfaction;
};
#endif