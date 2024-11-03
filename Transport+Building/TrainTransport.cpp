#include "TrainTransport.h"

TrainTransport::TrainTransport(TrainVehicle* vehicle) {
    this->vehicle = vehicle;
}

TrainTransport::~TrainTransport() {
    delete this->vehicle;
}

void TrainTransport::travel(){
    cout << "Traveling with " << this->vehicle->getName() << endl;
}

TrainVehicle* TrainTransport::getVehicle(){
    return this->vehicle;
}