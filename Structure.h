
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

        virtual void addUtilities(string &request, Structure* s) ;

        virtual float getKilowatts() ;
        virtual float getAvailableWater();
        virtual float getSewageAmount();
        virtual float getWasteAmount();

        virtual void setKilowatts(float kw);
        virtual void setAvailableWater(float water) ;
        virtual void setSewageAmount(float sewage) ;
        virtual void setWasteAmount(float waste) ;

};

#endif