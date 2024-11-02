#include "MaintenanceCostReducer.h"

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

float MaintenanceCostReducer::getMaintenance() 
{
    float originalCost = StructureDecorator::getMaintenance(); 
    return originalCost * (1 - reductionPercentage / 100); 
}