#include "BasicStructure.h"

BasicStructure::BasicStructure(const string& name, float maintenance, float resource, float satisfaction ) : name(name), maintenanceCost(maintenance), ResourceConsumption(resource), citizenSatisfactionImpact(satisfaction)
{
    
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
