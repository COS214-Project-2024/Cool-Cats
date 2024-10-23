#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include "AirVehicle.h"

using namespace std;


class Passenger : public AirVehicle
{
    private:
        int capacity;
        int maxCapacity;
        string name = "General Passenger";
    public:
        Passenger();
        ~Passenger();
        AirVehicle* clone();
        bool isFull();
        void setCapacity(int cap);
        void setMaxCapacity(int cap);
        string getName();
        void setName(string name);

    protected:
        

};

#endif