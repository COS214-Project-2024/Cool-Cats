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

};

#endif