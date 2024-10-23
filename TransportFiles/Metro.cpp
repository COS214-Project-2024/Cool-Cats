#include "Metro.h"

Metro::Metro() {}

Metro::~Metro() {}

TrainVehicle* Metro::clone(){
    return this;
}

void Metro::setCapacity(int cap){
    this->capacity = cap;
}

void Metro::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

bool Metro::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

string Metro::getName(){
    return this->name;
}

void Metro::setName(string name){
    this->name = name;
}