#include "PublicTransport.h"

PublicTransport::PublicTransport(PublicVehicle* vehicle) {
    this->vehicle = vehicle;
}

PublicTransport::~PublicTransport() {
    delete this->vehicle;
}

void PublicTransport::travel(){
    cout << "Traveling with " << this->vehicle->getName() << endl;
}

PublicVehicle* PublicTransport::getVehicle(){
    return this->vehicle;
}