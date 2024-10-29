#ifndef CITIZEN_H
#define CITIZEN_H

#include <vector>

#include "Structure.h"
// #include "PopulationMemento"
#include "CitizenIterator.h"


class Citizen
{
    public:
        Citizen();
        Citizen(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home);
        static void addCitizen(std::unique_ptr<Citizen> newCitizen);
        static void removeCitizen(Citizen* target);
        static int getPopulationCount();
        virtual void addService(std::string newService);
        virtual void removeService(std::string oldService);
        virtual void moveHomes(std::shared_ptr<Structure> newHome);
        double getSatisfaction();
        void setSatisfaction(double satisfaction);
        std::string getEmploymentStatus();
        void setEmploymentStatus(std::string employment);
        void determineMayor();
        virtual CitizenIterator* createCitizenIterator() = 0;
        // PopulationMemento* createMemento();
        // void setMemento(PopulationMemento* memento);
        
        
    protected:
        std::vector<std::string> services;
        static std::vector<std::unique_ptr<Citizen>> citizens;
        std::vector<Mayor*> getMayors();

    private:
        std::string employmentStatus;
        std::shared_ptr<Structure> home;
        double satisfaction;
};
#endif