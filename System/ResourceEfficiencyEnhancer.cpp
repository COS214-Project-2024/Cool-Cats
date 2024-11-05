#include "ResourceEfficiencyEnhancer.h"

/// @brief Constructs a ResourceEfficiencyEnhancer decorator to enhance the resource efficiency of a structure.
/// @param structure A pointer to the Structure to be decorated.
/// @param boost The percentage boost to be applied to the structure's resource efficiency.
/// @throws std::out_of_range if the boost value is not between 0 and 100.
ResourceEfficiencyEnhancer::ResourceEfficiencyEnhancer(Structure* structure, float boost) 
    : StructureDecorator(structure), efficiencyBoost(boost) 
{
    // Range check
    if (boost < 0.0f || boost > 100.0f) {
        throw std::out_of_range("Efficiency boost must be between 0 and 100.");
    }
}

/// @brief Retrieves the reduced resource consumption for the decorated structure.
/// @return The resource consumption after applying the specified efficiency boost.
float ResourceEfficiencyEnhancer::getResourceConsumption() 
{
    float originalConsumption = StructureDecorator::getResourceConsumption(); 
    return originalConsumption * (1 - efficiencyBoost / 100); 
}
