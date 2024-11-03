#ifndef SATISFACTIONENHANCER_H
#define SATISFACTIONENHANCER_H

#include <iostream>
#include <stdexcept>
#include "StructureDecorator.h"

using namespace std;

class SatisfactionEnhancer : public StructureDecorator
{
    private:
        float satisfactionBoost;
    public:
        SatisfactionEnhancer(Structure* structure, float boost);
        float getCitizenSatisfactionImpact() override;
        

};

#endif