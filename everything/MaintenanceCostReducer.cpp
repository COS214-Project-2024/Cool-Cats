#include "MaintenanceCostReducer.h"

MaintenanceCostReducer::MaintenanceCostReducer(Structure* structure, float reduction): StructureDecorator(structure), reductionPercentage(reduction) 
{

}

float MaintenanceCostReducer::getMaintenance() 
{
    float originalCost = StructureDecorator::getMaintenance(); 
    return originalCost * (1 - reductionPercentage / 100); 
}