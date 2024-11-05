#ifndef AIRPORTTRANSPORT_H
#define AIRPORTTRANSPORT_H

#include <iostream>
#include "AirVehicle.h"
#include "Transport.h"

using namespace std;

class AirportTransport: public Transport
{
    private:
        AirVehicle* vehicle;
    public:
        AirportTransport(AirVehicle* vehicle);
        ~AirportTransport();
        AirVehicle* getVehicle();
        void travel();

};

#endif