#include "BasicStructure.h"

BasicStructure::BasicStructure(const string& name, float maintenance, float resource, float satisfaction ) : name(name), maintenanceCost(maintenance), ResourceConsumption(resource), citizenSatisfactionImpact(satisfaction)
{
    
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
