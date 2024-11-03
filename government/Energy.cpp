#include "Energy.h"

Energy::Energy(ResourceMediator* mediator)
    : Government(mediator), energyProduced(0), energyConsumed(0), energyStored(0) {}

void Energy::produceEnergy(double amount) {
    energyProduced += amount;
    storeEnergy(amount);
}

void Energy::consumeEnergy(double amount) {
    energyConsumed += amount;
    energyStored -= amount;
}

void Energy::storeEnergy(double amount) {
    energyStored += amount;
}

double Energy::getEnergyStored() const {
    return energyStored;
}