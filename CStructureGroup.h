#ifndef CSTRUCTUREGROUP_H
#define CSTRUCTUREGROUP_H

#include <iostream>
#include "StructureGroup.h"
#include "CStructIterator.h"
#include <vector>
using namespace std;

class CStructureGroup :public StructureGroup
{
    private:
        vector<Structure*> structures;

    public:
        void add(Structure* structure) override;
        void remove(Structure* structure) override;
        vector<Structure*> getChildren() override;
        StructureIterator* createIterator();
        float getMaintenance() override;
        float getResourceConsumption() override;
        float getCitizenSatisfactionImpact() override;

        ~CStructureGroup();

};

#endif