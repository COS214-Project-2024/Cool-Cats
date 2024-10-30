#ifndef ROADSUBJECT_H
#define ROADSUBJECT_H

#include <iostream>
#include "Transportation.h"
#include <vector>
#include <algorithm>

using namespace std;

class RoadSubject
{
    private:
        vector<Transportation*> observerList;
    public:
        //RoadSubject();
        void attach(Transportation* observer);
        void detach(Transportation* observer);
        void notify();
        virtual string getName() = 0;
        virtual float getMaintenanceCost() = 0;
        virtual float getResourceConsumption() = 0;
        virtual float getCitizenSatisfactionImpact() = 0;
        //~RoadSubject();

};

#endif