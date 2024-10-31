#ifndef BASICSTRUCTURE_H
#define BASICSTRUCTURE_H

#include <iostream>
#include "Structure.h"

using namespace std;

class BasicStructure : public Structure {

    private:
        string name;
        float maintenanceCost;
        float ResourceConsumption;
        float citizenSatisfactionImpact;

    public:
        BasicStructure(const string& name, float maintenance, float resource, float satisfaction);
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