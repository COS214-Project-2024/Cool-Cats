#ifndef STRUCTUREGROUP_H
#define STRUCTUREGROUP_H

#include <iostream>
#include <vector>
#include "Structure.h"
#include "StructureIterator.h"

using namespace std;

class StructureGroup : public Structure
{
    private:

    public:
        void add(Structure* structure) override;
        void remove(Structure* structure) override;
        vector<Structure*> getChildren() override;
        float getMaintenance() override;
        float getResourceConsumption() override;
        float getCitizenSatisfactionImpact() override;
        StructureIterator* createIterator();

        ~StructureGroup();

};

#endif