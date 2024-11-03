#include "Road.h"

Road::Road(string name, float maintenance, float resource, float satisfaction) {
    this->name = name;
    this->MaintenanceCost = maintenance;
    this->ResourceConsumption = resource;
    this->CitizenSatisfaction = satisfaction;
}

Road::~Road() {
    delete this->roadState;
}

void Road::setState(RoadState* state){
    this->roadState = state;
}

RoadState* Road::getState(){
    return this->roadState;
}

bool Road::checkState(){
    return this->roadState->request();
}

string Road::getName(){
    return this->name;
}

float Road::getMaintenanceCost(){
    return this->MaintenanceCost;
}

float Road::getResourceConsumption(){
    return this->ResourceConsumption;
}

float Road::getCitizenSatisfactionImpact(){
    return this->CitizenSatisfaction;
}