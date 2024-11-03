#ifndef PUBLICTRANSPORT_H
#define PUBLICTRANSPORT_H

#include <iostream>
#include "PublicVehicle.h"
#include "Transport.h"

using namespace std;

class PublicTransport: public Transport
{
    private:
        PublicVehicle* vehicle;
    public:
        PublicTransport(PublicVehicle* vehicle);
        ~PublicTransport();
        PublicVehicle* getVehicle();
        void travel();

};

#endif