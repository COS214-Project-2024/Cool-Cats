#include "PublicTransport.h"

/// @brief Constructs a PublicTransport object with a specified public vehicle.
/// @param vehicle A pointer to a PublicVehicle object used for public transport.
PublicTransport::PublicTransport(PublicVehicle* vehicle) {
    this->vehicle = vehicle;
}

/// @brief Destructor for the PublicTransport object. Frees the associated PublicVehicle object.
PublicTransport::~PublicTransport() {
    delete this->vehicle;
}

/// @brief Initiates travel using the associated public vehicle, displaying the vehicle's name.
void PublicTransport::travel(){
    cout << "Traveling with " << this->vehicle->getName() << endl;
}

/// @brief Retrieves the PublicVehicle associated with this PublicTransport.
/// @return A pointer to the PublicVehicle object used by this PublicTransport.
PublicVehicle* PublicTransport::getVehicle(){
    return this->vehicle;
}
