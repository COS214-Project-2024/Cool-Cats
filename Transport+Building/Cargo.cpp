#include "Cargo.h"

Cargo::Cargo(string name) {
    this->name = name;
}

Cargo::~Cargo() {}

AirVehicle* Cargo::clone(){
    return this;
}

void Cargo::setCapacity(int cap){
    this->capacity = cap;
}

void Cargo::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

bool Cargo::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

string Cargo::getName(){
    return this->name;
}
