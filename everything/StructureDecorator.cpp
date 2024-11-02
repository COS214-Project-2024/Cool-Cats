#include "StructureDecorator.h"

StructureDecorator::StructureDecorator(Structure* structure) : decoratedStructure(structure)
{
    if (!decoratedStructure) {
        throw std::invalid_argument("Cannot decorate a null structure.");
    }
}

StructureDecorator::~StructureDecorator() 
{
    
    delete decoratedStructure;
}

string StructureDecorator::getName() {
    return decoratedStructure->getName();
}

float StructureDecorator::getMaintenance() 
{
    return decoratedStructure->getMaintenance();
}

float StructureDecorator::getResourceConsumption() 
{
    return decoratedStructure->getResourceConsumption();
}

float StructureDecorator::getCitizenSatisfactionImpact() 
{
    return decoratedStructure->getCitizenSatisfactionImpact();
}