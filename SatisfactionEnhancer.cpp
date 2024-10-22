#include "SatisfactionEnhancer.h"

SatisfactionEnhancer::SatisfactionEnhancer(Structure* structure, float boost) : StructureDecorator(structure), satisfactionBoost(boost) 
{

}

float SatisfactionEnhancer::getCitizenSatisfactionImpact() 
{
    float originalSatisfaction = StructureDecorator::getCitizenSatisfactionImpact(); 
    return originalSatisfaction + satisfactionBoost; 
}