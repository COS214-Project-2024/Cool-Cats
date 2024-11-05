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
};

#endif