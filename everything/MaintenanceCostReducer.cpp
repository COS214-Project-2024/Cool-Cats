#include "MaintenanceCostReducer.h"

/// @brief Constructs a MaintenanceCostReducer decorator to reduce the maintenance cost of a structure.
/// @param structure A pointer to the Structure to be decorated.
/// @param reduction The percentage reduction to be applied to the structure's maintenance cost.
/// @throws std::invalid_argument if the provided structure is null.
/// @throws std::out_of_range if the reduction percentage is not between 0 and 100.
MaintenanceCostReducer::MaintenanceCostReducer(Structure* structure, float reduction): StructureDecorator(structure), reductionPercentage(reduction) 
{
    if (!structure) {
        throw std::invalid_argument("Cannot apply MaintenanceCostReducer to a null structure.");
    }

    //range check
    if (reduction < 0.0f || reduction > 100.0f) {
        throw std::out_of_range("Reduction percentage must be between 0 and 100.");
    }
}

/// @brief Retrieves the reduced maintenance cost for the decorated structure.
/// @return The maintenance cost after applying the specified reduction percentage.
float MaintenanceCostReducer::getMaintenance() 
{
    float originalCost = StructureDecorator::getMaintenance(); 
    return originalCost * (1 - reductionPercentage / 100); 
}