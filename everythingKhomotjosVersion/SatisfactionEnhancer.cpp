#include "SatisfactionEnhancer.h"

/// @brief Constructs a SatisfactionEnhancer decorator to enhance the citizen satisfaction impact of a structure.
/// @param structure A pointer to the Structure to be decorated.
/// @param boost The amount to boost the citizen satisfaction impact.
/// @throws std::out_of_range if the boost value is negative or too large.
SatisfactionEnhancer::SatisfactionEnhancer(Structure* structure, float boost) 
    : StructureDecorator(structure), satisfactionBoost(boost) 
{
    // Range check
    if (boost < 0.0f) {
        throw std::out_of_range("Satisfaction boost must be non-negative.");
    }
}

/// @brief Retrieves the enhanced citizen satisfaction impact for the decorated structure.
/// @return The citizen satisfaction impact after applying the specified boost.
float SatisfactionEnhancer::getCitizenSatisfactionImpact() 
{
    float originalSatisfaction = StructureDecorator::getCitizenSatisfactionImpact(); 
    return originalSatisfaction + satisfactionBoost; 
}
