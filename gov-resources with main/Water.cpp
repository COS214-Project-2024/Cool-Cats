#include "Water.h"
#include <iostream>

Water::Water() : waterLiters(2000) {}

void Water::supplyWater(int amount) {
    if (waterLiters >= amount) {
        waterLiters -= amount;
        std::cout << "Supplied " << amount << " liters of water. Remaining water: " << waterLiters << std::endl;
    } else {
        std::cout << "Insufficient water!" << std::endl;
    }
}
