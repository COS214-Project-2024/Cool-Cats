#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "RoadSubject.h"
#include "RoadState.h"

using namespace std;

class Road : public RoadSubject
{
    private:
        RoadState* roadState;
        string name;
        float MaintenanceCost;
        float ResourceConsumption;
        float CitizenSatisfaction;
    public:
        Road(string name, float maintenance, float resource, float satisfaction);
        void setState(RoadState* state);
        RoadState* getState();
        bool checkState();
        string getName();
        float getMaintenanceCost();
        float getResourceConsumption();
        float getCitizenSatisfactionImpact();
        ~Road();

};

#endif