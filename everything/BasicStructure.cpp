#include "BasicStructure.h"

BasicStructure::BasicStructure(const string& name, char Btype, int capacity)
{
    this->name = name;
    this->type = Btype;
    if ( capacity > 1000 && capacity <= 0){
        throw std::invalid_argument("All parameters must be positive and less than 1000.");
    }


    this->maxCitizen = capacity;
    switch (Btype)
    {
    case 'R':
        maintenanceCost = 20*capacity;
        ResourceConsumption = 0.5*capacity;
        citizenSatisfactionImpact = 100;
        break;
        
    case 'C':
        maintenanceCost = 50*capacity;
        ResourceConsumption = 1.3*capacity;
        citizenSatisfactionImpact = 80;
        break;

    case 'L':
        maintenanceCost = 30*capacity;
        ResourceConsumption = 0.8*capacity;
        citizenSatisfactionImpact = 100;
        break;

    case 'I' :
        maintenanceCost = 70*capacity;
        ResourceConsumption = 1.5*capacity;
        citizenSatisfactionImpact = 40;
        break;
    
    default:
        break;
    }
}


void BasicStructure::addcitizen(Citizen* c )
{
    if( c == NULL){
        throw invalid_argument("Citizen cannot be NULL"); 
    }

    // Check if there is enough space in the structure
    if((numCitizen + 1) > maxCitizen ){
        throw invalid_argument("Structure is already full");
    }
    
    numCitizen++;
}

string BasicStructure::getType()
{
    switch (type)
    {
    case 'R':
        return "Residential";
        break;
    case 'C':
        return "Commercial";
        break;

    case 'I':
        return "Industrial";
        break;

    case 'L':
        return "Landmark";
        break;
    default:
        break;
    }
}

void BasicStructure::removeCitizen()
{
    numCitizen--;
}

void BasicStructure::add(Structure* structure) {
    throw std::runtime_error("Operation not supported: BasicStructure is a leaf and cannot contain children.");
}

void BasicStructure::remove(Structure* structure) {
    throw std::runtime_error("Operation not supported: BasicStructure is a leaf and cannot contain children.");
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
    // No resources to deallocate
}