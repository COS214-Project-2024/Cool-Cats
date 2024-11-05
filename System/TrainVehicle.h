#ifndef TRAINVEHICLE_H
#define TRAINVEHICLE_H

#include <iostream>

using namespace std;

class TrainVehicle
{
    private:
    public:
        TrainVehicle();
        ~TrainVehicle();
        virtual TrainVehicle* clone() = 0;
        virtual bool isFull() = 0;
        virtual void setCapacity(int cap) = 0;
        virtual void setMaxCapacity(int cap) = 0;
        virtual string getName() = 0;
    protected:
        
};

#endif