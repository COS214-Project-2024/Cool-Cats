#include "Freight.h"

Freight::Freight() {}

Freight::~Freight() {}

TrainVehicle* Freight::clone(){
    return this;
}

void Freight::setCapacity(int cap){
    this->capacity = cap;
}

void Freight::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

bool Freight::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

string Freight::getName(){
    return this->name;
}

void Freight::setName(string name){
    this->name = name;
}