#ifndef ENERGY_H
#define ENERGY_H

#include "Government.h"

class Energy : public Government {
private:
    double energyProduced;
    double energyConsumed;
    double energyStored;

public:
    Energy(ResourceMediator* mediator);
    
    void produceEnergy(double amount);
    void consumeEnergy(double amount);
    void storeEnergy(double amount);
    double getEnergyStored() const;
};

#endif