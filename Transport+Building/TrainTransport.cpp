#include "TrainTransport.h"

/// @brief Constructs a TrainTransport object with a specified train vehicle.
/// @param vehicle A pointer to a TrainVehicle object used for train transport.
TrainTransport::TrainTransport(TrainVehicle* vehicle) {
    this->vehicle = vehicle;
}

/// @brief Destructor for the TrainTransport object. Frees the associated TrainVehicle object.
TrainTransport::~TrainTransport() {
    delete this->vehicle;
}

/// @brief Initiates travel using the associated train vehicle, displaying the vehicle's name.
void TrainTransport::travel(){
    cout << "Traveling with " << this->vehicle->getName() << endl;
}

/// @brief Retrieves the TrainVehicle associated with this TrainTransport.
/// @return A pointer to the TrainVehicle object used by this TrainTransport.
TrainVehicle* TrainTransport::getVehicle(){
    return this->vehicle;
}
