#ifndef TRAINTRANSPORT_H
#define TRAINTRANSPORT_H

#include <iostream>
#include "TrainVehicle.h"
#include "Transport.h"

using namespace std;

class TrainTransport: public Transport
{
    private:
        TrainVehicle* vehicle;
    public:
        TrainTransport(TrainVehicle* vehicle);
        ~TrainTransport();
        TrainVehicle* getVehicle();
        void travel();

};

#endif