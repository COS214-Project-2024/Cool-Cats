#include "CityResourceMediator.h"
#include <iostream>

CityResourceMediator::CityResourceMediator(Materials& m, Energy& e, Water& w) 
    : materials(m), energy(e), water(w) {}

void CityResourceMediator::coordinateResources(const std::string& projectType, int materialsAmount, int energyAmount, int waterAmount) {
    std::cout << "Coordinating resources for: " << projectType << std::endl;
    materials.supplyMaterials(materialsAmount);
    energy.supplyEnergy(energyAmount);
    water.supplyWater(waterAmount);
    std::cout << "Resource allocation complete for: " << projectType << std::endl;
}
