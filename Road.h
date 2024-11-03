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
    public:
        Road(string name);
        void setState(RoadState* state);
        RoadState* getState();
        bool checkState();
        string getName();
        ~Road();

};

#endif