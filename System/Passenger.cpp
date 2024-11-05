#include "Passenger.h"

/// @brief Constructs a Passenger object with a specified name.
/// @param name The name of the passenger.
Passenger::Passenger(string name) {
    this->name = name;
}

/// @brief Destructor for the Passenger object.
Passenger::~Passenger() {}

/// @brief Creates a clone of the Passenger object.
/// @return A pointer to the cloned AirVehicle (in this case, the same Passenger object).
AirVehicle* Passenger::clone(){
    return this;
}

/// @brief Sets the current capacity associated with the passenger.
/// @param cap The capacity to be set.
void Passenger::setCapacity(int cap){
    this->capacity = cap;
}

/// @brief Sets the maximum capacity associated with the passenger.
/// @param cap The maximum capacity to be set.
void Passenger::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

/// @brief Checks if the passenger's assigned vehicle is full and displays the remaining capacity if not full.
/// @return True if the vehicle is full, otherwise false.
bool Passenger::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This Passenger Plane is now full." << std::endl;
        return true;
    }
    std::cout << "This Passenger Plane has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

/// @brief Retrieves the name of the passenger.
/// @return The name of the passenger as a string.
string Passenger::getName(){
    return this->name;
}
