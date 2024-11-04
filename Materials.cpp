#include "Materials.h"

Materials::Materials(ResourceMediator* mediator)
    : Government(mediator), materialsAvailable(0), materialsUsed(0) {}

void Materials::supplyMaterials(double amount) {
    materialsAvailable += amount;
}

void Materials::useMaterials(double amount) {
    if (materialsAvailable >= amount) {
        materialsUsed += amount;
        materialsAvailable -= amount;
    }
}

double Materials::getMaterialsAvailable() const {
    return materialsAvailable;
}
