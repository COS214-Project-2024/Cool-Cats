#include "AirportTransport.h"

AirportTransport::AirportTransport(AirVehicle* vehicle) {
    this->vehicle = vehicle;
}

AirportTransport::~AirportTransport() {
    delete this->vehicle;
}

void AirportTransport::travel(){
    cout << "Traveling with " << this->vehicle->getName() << endl;
}