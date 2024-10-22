#include "CStructureGroup.h"

void CStructureGroup::add(Structure* structure) 
{
    structures.push_back(structure);
}

void CStructureGroup::remove(Structure* structure) 
{
    auto it = std::remove(structures.begin(), structures.end(), structure);
    if (it != structures.end()) {
        structures.erase(it);
    }
}

StructureIterator* CStructureGroup::createIterator() 
{
    return new CStructIterator(structures);
}

vector<Structure*> CStructureGroup::getChildren() 
{
    return structures; 
}

float CStructureGroup::getMaintenance() 
{
    float totalMaintenance = 0;
    for (Structure* structure : structures) {
        totalMaintenance += structure->getMaintenance();
    }
    return totalMaintenance;
}

float CStructureGroup::getResourceConsumption() 
{
    float totalResource = 0;
    for (Structure* structure : structures) {
        totalResource += structure->getResourceConsumption();
    }
    return totalResource;
}

CStructureGroup::~CStructureGroup() {
    for (Structure* structure : structures) {
        delete structure; 
    }
}