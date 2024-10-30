#ifndef CITIZEN_H
#define CITIZEN_H

#include <vector>
#include <memory>
#include <string>

#include "../Buildings/Structure.h"
// #include "PopulationMemento"

class Mayor;
class CitizenIterator;

class Citizen
{
    public:
        Citizen();
        Citizen(std::string employmentStatus, double satisfaction, std::shared_ptr<Structure> home);
        static void addCitizen(std::unique_ptr<Citizen> newCitizen);
        static void removeCitizen(Citizen* target);
        static int getPopulationCount();
        void addService(std::string newService);
        void removeService(std::string oldService);
        void moveHomes(std::shared_ptr<Structure> newHome);
        double getSatisfaction();
        void setSatisfaction(double satisfaction);
        std::string getEmploymentStatus();
        void setEmploymentStatus(std::string employment);
        void determineMayor();
        std::vector<Mayor*> getMayors();
        virtual CitizenIterator* createCitizenIterator() = 0;
        // PopulationMemento* createMemento();
        // void setMemento(PopulationMemento* memento);
        
        
    protected:
        std::vector<std::string> services;
        static std::vector<std::unique_ptr<Citizen>> citizens;

    private:
        std::string employmentStatus;
        std::shared_ptr<Structure> home;
        double satisfaction;
};
#endif