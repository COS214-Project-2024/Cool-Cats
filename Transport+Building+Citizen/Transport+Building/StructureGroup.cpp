#include "StructureGroup.h"

vector<Structure*> StructureGroup::getChildren() {
    return structures; 
}

StructureGroup::StructureGroup(const string& groupName) : name(groupName){}

void StructureGroup::add(Structure* structure)
{
    structures.push_back(structure);
}

void StructureGroup::remove(Structure* structure)
{
    auto it = std::remove(structures.begin(), structures.end(), structure);
    structures.erase(it, structures.end());
}

CStructIterator* StructureGroup::createIterator()
{
    return new CStructIterator(structures);
}

float StructureGroup::getMaintenance() {
    // Sum the maintenance cost of all children
    float totalMaintenance = 0;
    for (Structure* child : getChildren()) {
        totalMaintenance += child->getMaintenance();
    }
    return totalMaintenance;
}

float StructureGroup::getResourceConsumption() {
    // Sum the resource consumption of all children
    float totalResource = 0;
    for (Structure* child : getChildren()) {
        totalResource += child->getResourceConsumption();
    }
    return totalResource;
}

float StructureGroup::getCitizenSatisfactionImpact() {
    // Sum the citizen satisfaction impact of all children
    float totalSatisfaction = 0;
    for (Structure* child : getChildren()) {
        totalSatisfaction += child->getCitizenSatisfactionImpact();
    }
    return totalSatisfaction;
}

StructureGroup::~StructureGroup() 
{
    for(auto* structure : structures){
        delete structure;
    }
}

string StructureGroup::getName() 
{
    return name;
}