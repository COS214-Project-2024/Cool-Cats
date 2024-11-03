#include "Energy.h"
#include <iostream>

Energy::Energy() : energyUnits(500) {}

void Energy::supplyEnergy(int amount) {
    if (energyUnits >= amount) {
        energyUnits -= amount;
        std::cout << "Supplied " << amount << " energy units. Remaining energy: " << energyUnits << std::endl;
    } else {
        std::cout << "Insufficient energy!" << std::endl;
    }
}
