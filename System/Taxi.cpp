#include "Taxi.h"

/// @brief Constructs a Taxi object with a specified name.
/// @param name The name of the taxi.
Taxi::Taxi(string name) {
    this->name = name;
}

/// @brief Destructor for the Taxi object.
Taxi::~Taxi() {}

/// @brief Creates a clone of the Taxi object.
/// @return A pointer to the cloned PublicVehicle (in this case, the same Taxi object).
PublicVehicle* Taxi::clone(){
    return this;
}

/// @brief Sets the current capacity of the taxi.
/// @param cap The capacity to be set.
void Taxi::setCapacity(int cap){
    this->capacity = cap;
}

/// @brief Sets the maximum capacity of the taxi.
/// @param cap The maximum capacity to be set.
void Taxi::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

/// @brief Checks if the taxi is full and displays the remaining capacity if not full.
/// @return True if the taxi is full, otherwise false.
bool Taxi::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This taxi is now full." << std::endl;
        return true;
    }
    std::cout << "This taxi has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

/// @brief Retrieves the name of the taxi.
/// @return The name of the taxi as a string.
string Taxi::getName(){
    return this->name;
}
