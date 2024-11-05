
#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
#include <vector>

using namespace std;

class Structure
{
    private:

    public:
        virtual ~Structure() = default;
        virtual string getName() = 0;
        virtual float getMaintenance() =0;
        virtual float getResourceConsumption() =0;      
        virtual float getCitizenSatisfactionImpact() = 0;
        virtual void add(Structure* structure) = 0;
        virtual void remove(Structure* structure) = 0;
        virtual vector<Structure*> getChildren() = 0;

        virtual float getKilowatts() = 0;
        virtual void addUtilities(string &request, Structure* s) = 0;
        virtual float getAvailableWater()= 0;
        virtual float getSewageAmount()= 0;
        virtual float getWasteAmount()= 0;

        virtual void setKilowatts(float kw)= 0;
        virtual void setAvailableWater(float water)= 0;
        virtual void setSewageAmount(float sewage)= 0;
        virtual void setWasteAmount(float waste)= 0;
        virtual void subTract()= 0;



};

#endif