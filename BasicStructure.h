#ifndef BASICSTRUCTURE_H
#define BASICSTRUCTURE_H

#include <iostream>
#include "Structure.h"
#include "Citizen.h"

using namespace std;

class BasicStructure : public Structure {

    private:
        int numCitizen;
        string type;
        string name;
        float maintenanceCost;
        float ResourceConsumption;
        float citizenSatisfactionImpact;
        float kilowatts;
        float availableWater;
        float sewageThere;
        float wasteThere;

    public:
        BasicStructure(const string& name, string type, float maintenance, float resource, float satisfaction , int capacity);
        void addcitizen(Citizen *c);
        string getType();
        void removeCitizen();
        string getName() override;
        float getMaintenance() override;
        float getResourceConsumption() override;
        float getCitizenSatisfactionImpact() override;
        void add(Structure* structure) override;
        void remove(Structure* structure) override;
        vector<Structure*> getChildren() override;
        float getKilowatts();
        float getAvailableWater();
        float getSewageAmount();
        float getWasteAmount();

        void setKilowatts(float kw);
        void setAvailableWater(float water);
        void setSewageAmount(float sewage);
        void setWasteAmount(float waste);


        ~BasicStructure();

};

#endif