#include "Tram.h"

Tram::Tram() {}

Tram::~Tram() {}

TrainVehicle* Tram::clone(){
    return this;
}

void Tram::setCapacity(int cap){
    this->capacity = cap;
}

void Tram::setMaxCapacity(int cap){
    this->maxCapacity = cap;
}

bool Tram::isFull(){
    if(this->capacity >= this->maxCapacity){
        std::cout << "This bus is now full." << std::endl;
        return true;
    }
    std::cout << "This bus has space for " << maxCapacity - capacity << " more people." << std::endl;
    return false;
}

string Tram::getName(){
    return this->name;
}

void Tram::setName(string name){
    this->name = name;
}