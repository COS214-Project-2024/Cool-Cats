#include "Materials.h"
#include <iostream>

Materials::Materials() : stock(1000) {}

void Materials::supplyMaterials(int amount) {
    if (stock >= amount) {
        stock -= amount;
        std::cout << "Supplied " << amount << " materials. Remaining stock: " << stock << std::endl;
    } else {
        std::cout << "Insufficient materials!" << std::endl;
    }
}
