#ifndef BASICSTRUCTURE_H
#define BASICSTRUCTURE_H

#include <iostream>
#include "Structure.h"
#include "Citizen.h"

using namespace std;

class BasicStructure : public Structure {

    private:
        int numCitizen;
        int maxCitizen;
        char type;
        string name;
        float maintenanceCost;
        float ResourceConsumption;
        float citizenSatisfactionImpact;

    public:
        BasicStructure(const string& name, char Btype, int capacity);
        void addcitizen(int number);
        string getType();
        void removeCitizen(int number);
        string getName() override;
        float getMaintenance() override;
        float getResourceConsumption() override;
        float getCitizenSatisfactionImpact() override;
        void add(Structure* structure) override;
        void remove(Structure* structure) override;
        vector<Structure*> getChildren() override;


        ~BasicStructure();

};

#endif