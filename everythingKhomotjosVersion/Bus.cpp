#include "Bus.h"

Bus::Bus() {}

Bus::~Bus() {}

PublicVehicle* Bus::clone(){
    return this;
}

void Bus::setCapacity(int cap){
    this->capacity = cap;
}

void Bus::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

bool Bus::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

string Bus::getName(){
    return this->name;
}

void Bus::setName(string name){
    this->name = name;
}