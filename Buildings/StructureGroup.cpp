#include "StructureGroup.h"

vector<Structure*> StructureGroup::getChildren() {
    return {}; 
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