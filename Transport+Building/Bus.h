#ifndef BUS_H
#define BUS_H

#include <iostream>
#include "PublicVehicle.h"

using namespace std;


class Bus : public PublicVehicle
{
    private:
        int capacity;
        int maxCapacity;
        string name = "General Bus";
    public:
        Bus(string name);
        ~Bus();
        PublicVehicle* clone();
        bool isFull();
        void setCapacity(int cap);
        void setMaxCapacity(int cap);
        string getName();

    protected:
        

};

#endif