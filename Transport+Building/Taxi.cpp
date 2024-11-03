#include "Taxi.h"

Taxi::Taxi(string name) {
    this->name = name;
}

Taxi::~Taxi() {}

PublicVehicle* Taxi::clone(){
    return this;
}

void Taxi::setCapacity(int cap){
    this->capacity = cap;
}

void Taxi::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

bool Taxi::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

string Taxi::getName(){
    return this->name;
}

