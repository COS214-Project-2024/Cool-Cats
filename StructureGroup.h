#ifndef STRUCTUREGROUP_H
#define STRUCTUREGROUP_H

#include <iostream>
#include <vector>
#include "Structure.h"
#include "CStructIterator.h"
#include <algorithm>

using namespace std;

class StructureGroup : public Structure
{
    private:
        vector<Structure*> structures;
        string name;
    public:
        explicit StructureGroup(const string& groupName);
        string getName() override ;
        void add(Structure* structure) override ;
        void remove(Structure* structure) ;
        vector<Structure*> getChildren() override;
        float getMaintenance() override;
        float getResourceConsumption() override;
        float getCitizenSatisfactionImpact() override;
        CStructIterator* createIterator();
        float getKilowatts()override{return 0;};
        void addUtilities(string &request, Structure* s) override{};
        float getAvailableWater()override{return 0;};
        float getSewageAmount()override{return 0;};
        float getWasteAmount()override{return 0;};

        void setKilowatts(float kw)override{};
        void setAvailableWater(float water)override{};
        void setSewageAmount(float sewage)override{};
        void setWasteAmount(float waste)override{};
        void subTract()override{};
        

        ~StructureGroup() ;

};

#endif