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
        StructureIterator* createIterator();

        ~StructureGroup() ;

};

#endif