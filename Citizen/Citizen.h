#ifndef CITIZEN_H
#define CITIZEN_H

#include <vector>
#include <string>

#include "../Buildings/Structure.h"
// #include "PopulationMemento"

class Mayor;
class CitizenIterator;

class Citizen
{
    public:
        Citizen();
        Citizen(std::string employmentStatus, double satisfaction, Structure* home);
        static int getPopulationCount();
        void addService(std::string newService);
        void removeService(std::string oldService);
        std::vector<std::string> getServices();
        void moveHomes(Structure* newHome);
        Structure* getHome();
        double getSatisfaction();
        void setSatisfaction(double satisfaction);
        std::string getEmploymentStatus();
        void setEmploymentStatus(std::string employment);
        virtual void vote() = 0;
        static void determineMayor();
        static std::vector<Mayor*> getMayors();
        virtual CitizenIterator* createCitizenIterator() = 0;
        // PopulationMemento* createMemento();
        // void setMemento(PopulationMemento* memento);
        virtual ~Citizen();
        
    protected:
        std::vector<std::string> services;
        static std::vector<Citizen*> citizens;

    private:
        std::string employmentStatus;
        Structure* home;
        double satisfaction;
        static void addCitizen(Citizen* newCitizen);
        static void removeCitizen(Citizen* target);
};
#endif