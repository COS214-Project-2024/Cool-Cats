#include "StructureDecorator.h"

/// @brief Constructs a structure decorator to add additional functionality to a base structure.
/// @param structure A pointer to the Structure to be decorated.
/// @throws std::invalid_argument if the provided structure is null.
StructureDecorator::StructureDecorator(Structure* structure) : decoratedStructure(structure)
{
    if (!decoratedStructure) {
        throw std::invalid_argument("Cannot decorate a null structure.");
    }
}

/// @brief Destructor for the structure decorator that ensures proper cleanup of the decorated structure.
StructureDecorator::~StructureDecorator() 
{
    
    delete decoratedStructure;
}

/// @brief Retrieves the name of the decorated structure.
/// @return The name of the structure as a string.
string StructureDecorator::getName() {
    return decoratedStructure->getName();
}

/// @brief Retrieves the maintenance cost of the decorated structure.
/// @return The maintenance cost of the structure as a float.
float StructureDecorator::getMaintenance() 
{
    return decoratedStructure->getMaintenance();
}

/// @brief Retrieves the resource consumption of the decorated structure.
/// @return The resource consumption of the structure as a float.
float StructureDecorator::getResourceConsumption() 
{
    return decoratedStructure->getResourceConsumption();
}

/// @brief Retrieves the citizen satisfaction impact of the decorated structure.
/// @return The citizen satisfaction impact as a float.
float StructureDecorator::getCitizenSatisfactionImpact() 
{
    return decoratedStructure->getCitizenSatisfactionImpact();
}