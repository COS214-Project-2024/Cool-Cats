#include "Passenger.h"

Passenger::Passenger(string name) {
    this->name = name;
}

Passenger::~Passenger() {}

AirVehicle* Passenger::clone(){
    return this;
}

void Passenger::setCapacity(int cap){
    this->capacity = cap;
}

void Passenger::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

bool Passenger::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

string Passenger::getName(){
    return this->name;
}
