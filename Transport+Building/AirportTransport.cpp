#include "AirportTransport.h"

/// @brief Constructs an AirportTransport object with a specified air vehicle.
/// @param vehicle A pointer to an AirVehicle object used for airport transport.
AirportTransport::AirportTransport(AirVehicle* vehicle) {
    this->vehicle = vehicle;
}

/// @brief Destructor for the AirportTransport object. Frees the allocated AirVehicle object.
AirportTransport::~AirportTransport() {
    delete this->vehicle;
}

/// @brief Initiates travel using the associated air vehicle, displaying the vehicle's name.
void AirportTransport::travel(){
    cout << "Traveling with " << this->vehicle->getName() << endl;
}

/// @brief Retrieves the AirVehicle associated with this AirportTransport.
/// @return A pointer to the AirVehicle object used by this AirportTransport.
AirVehicle* AirportTransport::getVehicle(){
    return this->vehicle;
}
