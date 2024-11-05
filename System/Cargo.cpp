#include "Cargo.h"

/// @brief Constructs a Cargo object with a specified name.
/// @param name The name of the cargo.
Cargo::Cargo(string name) {
    this->name = name;
}

/// @brief Destructor for the Cargo object.
Cargo::~Cargo() {}

/// @brief Creates a clone of the Cargo object.
/// @return A pointer to the cloned AirVehicle (in this case, the same Cargo object).
AirVehicle* Cargo::clone(){
    return this;
}

/// @brief Sets the current capacity of the cargo.
/// @param cap The capacity to be set.
void Cargo::setCapacity(int cap){
    this->capacity = cap;
}

/// @brief Sets the maximum capacity of the cargo.
/// @param cap The maximum capacity to be set.
void Cargo::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

/// @brief Checks if the cargo is full and displays the remaining capacity if not full.
/// @return True if the cargo is full, otherwise false.
bool Cargo::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This Cargo is now full." << std::endl;
        return true;
    }
    std::cout << "This Cargo has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

/// @brief Retrieves the name of the cargo.
/// @return The name of the cargo as a string.
string Cargo::getName(){
    return this->name;
}
