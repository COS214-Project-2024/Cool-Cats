#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <iostream>

using namespace std;

class AirVehicle
{
    private:
    public:
        AirVehicle();
        ~AirVehicle();
        virtual AirVehicle* clone() = 0;
        virtual bool isFull() = 0;
        virtual void setCapacity(int cap) = 0;
        virtual void setMaxCapacity(int cap) = 0;
        virtual string getName() = 0;
        virtual void setName(string name) = 0;
    protected:
        
};

#endif