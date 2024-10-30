#include "ResourceEfficiencyEnhancer.h"

ResourceEfficiencyEnhancer::ResourceEfficiencyEnhancer(Structure* structure, float boost) : StructureDecorator(structure), efficiencyBoost(boost) 
{

}

float ResourceEfficiencyEnhancer::getResourceConsumption() 
{
    float originalConsumption = StructureDecorator::getResourceConsumption(); 
    return originalConsumption * (1 - efficiencyBoost / 100); 
}