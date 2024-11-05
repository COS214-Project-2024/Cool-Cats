#ifndef TRAM_H
#define TRAM_H

#include <iostream>
#include "TrainVehicle.h"

using namespace std;


class Tram : public TrainVehicle
{
    private:
        int capacity;
        int maxCapacity;
        string name = "General Tram";
    public:
        Tram(string name);
        ~Tram();
        TrainVehicle* clone();
        bool isFull();
        void setCapacity(int cap);
        void setMaxCapacity(int cap);
        string getName();

    protected:
        

};

#endif