#ifndef METRO_H
#define METRO_H

#include <iostream>
#include "TrainVehicle.h"

using namespace std;


class Metro : public TrainVehicle
{
    private:
        int capacity;
        int maxCapacity;
        string name = "General Metro";
    public:
        Metro(string name);
        ~Metro();
        TrainVehicle* clone();
        bool isFull();
        void setCapacity(int cap);
        void setMaxCapacity(int cap);
        string getName();

    protected:
        

};

#endif