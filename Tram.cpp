#include "Tram.h"

/// @brief Constructs a Tram object with a specified name.
/// @param name The name of the tram.
Tram::Tram(string name) {
    this->name = name;
}

/// @brief Destructor for the Tram object.
Tram::~Tram() {}

/// @brief Creates a clone of the Tram object.
/// @return A pointer to the cloned TrainVehicle (in this case, the same Tram object).
TrainVehicle* Tram::clone(){
    return this;
}

/// @brief Sets the current capacity of the tram.
/// @param cap The capacity to be set.
void Tram::setCapacity(int cap){
    if(cap < -this->capacity || cap > this->maxCapacity){
        std::cout << "Invalid Tram Size" << std::endl;
    }
    else{
        this->capacity += cap;
    }
}

/// @brief Sets the maximum capacity of the tram.
/// @param cap The maximum capacity to be set.
void Tram::setMaxCapacity(int cap){
    if(cap < 0 || cap > 200){
        std::cout << "Invalid Tram Size" << std::endl;
    }
    else{
        this->maxCapacity = cap;
    }
}

/// @brief Checks if the tram is full and displays the remaining capacity if not full.
/// @return True if the tram is full, otherwise false.
bool Tram::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This tram is now full." << std::endl;
        return true;
    }
    std::cout << "This tram has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

/// @brief Retrieves the name of the tram.
/// @return The name of the tram as a string.
string Tram::getName(){
    return this->name;
}
