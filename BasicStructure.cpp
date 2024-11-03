#include "BasicStructure.h"

BasicStructure::BasicStructure(const string& name, string type, float maintenance, float resource, float satisfaction , int capacity)
{
    this->name = name;
    this->type = type;
    if (maintenance <= 0 || resource <= 0 || satisfaction < 0 || capacity <= 0){
        throw invalid_argument("Invalid values for BasicStructure");
    }
    this->numCitizen = capacity;
    this->maintenanceCost = maintenance;
    this->ResourceConsumption = resource;
    this->citizenSatisfactionImpact = satisfaction;
}

void BasicStructure::addcitizen(Citizen* c )
{
    if( c == NULL){
        throw invalid_argument("Citizen cannot be NULL"); 
    }

    // Check if there is enough space in the structure
    if(numCitizen >= this->numCitizen){
        throw invalid_argument("Structure is already full");
    }
    
    numCitizen++;
}

string BasicStructure::getType()
{
    return type;
}

void BasicStructure::removeCitizen()
{
    numCitizen--;
}

void BasicStructure::add(Structure* structure) {
    // Optionally: throw an error if not intended to be used
}

void BasicStructure::remove(Structure* structure) {
    // Optionally: throw an error if not intended to be used
}

std::vector<Structure*> BasicStructure::getChildren() {
    return {};  // Return an empty vector, as BasicStructure has no children
}

string BasicStructure::getName() 
{
    return name;
}

float BasicStructure::getMaintenance() 
{
    return maintenanceCost;
}

float BasicStructure::getResourceConsumption() 
{
    return ResourceConsumption;
}

float BasicStructure::getCitizenSatisfactionImpact() {
    return citizenSatisfactionImpact;
}

BasicStructure::~BasicStructure(){
    // No resources to deallocate, so no code needed here
}

float BasicStructure::getKilowatts() {
    return kilowatts;
}

// Setter for kilowatts
void BasicStructure::setKilowatts(float kw) {
    kilowatts = kw;
}

// Getter for availableWater
float BasicStructure::getAvailableWater() {
    return availableWater;
}

// Setter for availableWater
void BasicStructure::setAvailableWater(float water) {
    availableWater = water;
}

// Getter for sewageAmount
float BasicStructure::getSewageAmount() {
    return sewageThere;
}

// Setter for sewageAmount
void BasicStructure::setSewageAmount(float sewage) {
    sewageThere = sewage;
}

// Getter for wasteAmount
float BasicStructure::getWasteAmount() {
    return wasteThere;
}

// Setter for wasteAmount
void BasicStructure::setWasteAmount(float waste) {
    wasteThere = waste;
}