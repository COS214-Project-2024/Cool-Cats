#ifndef RESOURCEEFFICIENCYENHANCER_H
#define RESOURCEEFFICIENCYENHANCER_H

#include <iostream>
#include <stdexcept>
#include "StructureDecorator.h"

using namespace std;

class ResourceEfficiencyEnhancer : public StructureDecorator
{
    private:
        float efficiencyBoost;
    public:
        ResourceEfficiencyEnhancer(Structure* structure, float reduction);
        float getResourceConsumption() override;

};

#endif