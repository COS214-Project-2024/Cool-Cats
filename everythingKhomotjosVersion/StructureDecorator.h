#ifndef STRUCTUREDECORATOR_H
#define STRUCTUREDECORATOR_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Structure.h"


using namespace std;

class StructureDecorator : public Structure
{
    // private:
    //     Structure* decoratedStructure;

    protected:
        Structure* decoratedStructure;

    public:
        StructureDecorator(Structure* structure);
        virtual ~StructureDecorator();
        virtual string getName() override;
        virtual float getMaintenance() override;
        virtual float getResourceConsumption() override;
        virtual float getCitizenSatisfactionImpact() override;
         void add(Structure* structure) override {}            // No-op
        void remove(Structure* structure) override {}         // No-op
        vector<Structure*> getChildren() override { return {}; } // Returns an empty vector
        
};

#endif