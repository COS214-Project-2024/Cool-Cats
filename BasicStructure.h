#ifndef BASICSTRUCTURE_H
#define BASICSTRUCTURE_H

#include <iostream>
#include "Structure.h"
#include "Citizen.h"
#include "Utilities.h"
#include "PowerUtility.h"
#include "SewageUtility.h"
#include "WasteUtility.h"
#include "WaterUtility.h"

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

        float kilowatts;
        float availableWater;
        float sewageThere;
        float wasteThere;

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

        void addUtilities(string &request, Structure* s) override;

        float getKilowatts()override;
        float getAvailableWater()override;
        float getSewageAmount()override;
        float getWasteAmount()override;

        void setKilowatts(float kw)override;
        void setAvailableWater(float water)override;
        void setSewageAmount(float sewage)override;
        void setWasteAmount(float waste)override;
        ~BasicStructure();

};

#endif