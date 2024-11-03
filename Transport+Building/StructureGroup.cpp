#include "StructureGroup.h"

/// @brief Retrieves all child structures within the group.
/// @return A vector containing pointers to each child structure.
vector<Structure*> StructureGroup::getChildren() {
    return structures; 
}

/// @brief Constructs a StructureGroup with the specified name.
/// @param groupName The name of the structure group.
StructureGroup::StructureGroup(const string& groupName) : name(groupName){}

/// @brief Adds a structure to the group.
/// @param structure Pointer to the Structure to add.
/// @throws std::invalid_argument If the structure is null.
/// @throws std::runtime_error If the structure is already in the group.
void StructureGroup::add(Structure* structure)
{
    if (!structure) {
        throw std::invalid_argument("Cannot add a null structure.");
    }

    //if structure is already in the group
    if (std::find(structures.begin(), structures.end(), structure) != structures.end()) {
        throw std::runtime_error("Cannot add duplicate structure to the group.");
    }

    structures.push_back(structure);
}

/// @brief Removes a structure from the group.
/// @param structure Pointer to the Structure to remove.
/// @throws std::invalid_argument If the structure is null.
/// @throws std::runtime_error If the structure is not found in the group.
void StructureGroup::remove(Structure* structure)
{
    if (!structure) {
        throw std::invalid_argument("Cannot remove a null structure.");
    }

    auto it = std::find(structures.begin(), structures.end(), structure);
    if (it == structures.end()) {
        throw std::runtime_error("Structure not found in the group.");
    }

    structures.erase(it);
}

/// @brief Creates an iterator for iterating over all structures in the group.
/// @return A pointer to a CStructIterator object for this structure group.
CStructIterator* StructureGroup::createIterator()
{
    return new CStructIterator(structures);
}

/// @brief Calculates the total maintenance cost for all structures in the group.
/// @return The total maintenance cost.
float StructureGroup::getMaintenance() {
    // Sum the maintenance cost of all children
    float totalMaintenance = 0;
    for (Structure* child : getChildren()) {
        totalMaintenance += child->getMaintenance();
    }
    return totalMaintenance;
}

/// @brief Calculates the total resource consumption for all structures in the group.
/// @return The total resource consumption.
float StructureGroup::getResourceConsumption() {
    // Sum the resource consumption of all children
    float totalResource = 0;
    for (Structure* child : getChildren()) {
        totalResource += child->getResourceConsumption();
    }
    return totalResource;
}

/// @brief Calculates the average citizen satisfaction impact across all structures in the group,
/// ensuring the value remains within a 0-100% range.
/// @return The average citizen satisfaction impact for the group, capped at 100%.
float StructureGroup::getCitizenSatisfactionImpact() {
    if (structures.empty()) return 0; //  no structures in the group.

    float totalSatisfaction = 0;
    for (Structure* child : getChildren()) {
        totalSatisfaction += child->getCitizenSatisfactionImpact();
    }
    
    // Calculate the average and cap at 100.
    float averageSatisfaction = totalSatisfaction / structures.size();
    return averageSatisfaction > 100 ? 100 : averageSatisfaction;
}

/// @brief Destructor for StructureGroup, deletes all structures within the group.
StructureGroup::~StructureGroup() 
{
    for(auto* structure : structures){
        delete structure;
    }
}

/// @brief Gets the name of the structure group.
/// @return The name of the structure group.
string StructureGroup::getName() 
{
    return name;
}