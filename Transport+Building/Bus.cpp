#include "Bus.h"

/// @brief Constructs a Bus object with a specified name.
/// @param name The name of the bus.
Bus::Bus(string name) {
    this->name = name;
}

/// @brief Destructor for the Bus object.
Bus::~Bus() {}

/// @brief Creates a clone of the Bus object.
/// @return A pointer to the cloned PublicVehicle (in this case, the same Bus object).
PublicVehicle* Bus::clone(){
    return this;
}

/// @brief Sets the current capacity of the bus.
/// @param cap The capacity to be set. Must be between 0 and 70.
void Bus::setCapacity(int cap){
    if(cap < 0 || (this->maxCapacity - cap) < 0){
        std::cout << "Invalid Bus Size" << std::endl;
    }
    else{
        this->capacity = cap;
    }
}

/// @brief Sets the maximum capacity of the bus.
/// @param cap The maximum capacity to be set. Must be between 0 and 70.
void Bus::setMaxCapacity(int cap){
    if(cap < 0 || cap > 70){
        std::cout << "Invalid Bus Size" << std::endl;
    }
    else{
        this->maxCapacity = cap;
    }
}

/// @brief Checks if the bus is full and displays the remaining capacity if not full.
/// @return True if the bus is full, otherwise false.
bool Bus::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

/// @brief Retrieves the name of the bus.
/// @return The name of the bus as a string.
string Bus::getName(){
    return this->name;
}
