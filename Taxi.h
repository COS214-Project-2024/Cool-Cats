#ifndef TAXI_H
#define TAXI_H

#include <iostream>
#include "PublicVehicle.h"

using namespace std;


class Taxi : public PublicVehicle
{
    private:
        int capacity;
        int maxCapacity;
        string name = "General Taxi";
    public:
        Taxi(string name);
        ~Taxi();
        PublicVehicle* clone();
        bool isFull();
        void setCapacity(int cap);
        void setMaxCapacity(int cap);
        string getName();

    protected:
        

};

#endif