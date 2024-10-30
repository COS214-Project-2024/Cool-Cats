#ifndef STRUCTUREDECORATOR_H
#define STRUCTUREDECORATOR_H

#include <iostream>
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
        

};

#endif