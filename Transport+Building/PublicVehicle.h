#ifndef PUBLICVEHICLE_H
#define PUBLICVEHICLE_H

#include <iostream>

using namespace std;

class PublicVehicle
{
    private:
    public:
        PublicVehicle();
        ~PublicVehicle();
        virtual PublicVehicle* clone() = 0;
        virtual bool isFull() = 0;
        virtual void setCapacity(int cap) = 0;
        virtual void setMaxCapacity(int cap) = 0;
        virtual string getName() = 0;
    protected:
        
};

#endif