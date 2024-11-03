#ifndef FREIGHT_H
#define FREIGHT_H

#include <iostream>
#include "TrainVehicle.h"

using namespace std;


class Freight : public TrainVehicle
{
    private:
        int capacity;
        int maxCapacity;
        string name = "General Freight";
    public:
        Freight();
        ~Freight();
        TrainVehicle* clone();
        bool isFull();
        void setCapacity(int cap);
        void setMaxCapacity(int cap);
        string getName();
        void setName(string name);

    protected:
        

};

#endif