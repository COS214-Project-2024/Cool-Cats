#ifndef ENERGY_H
#define ENERGY_H

class Energy {
private:
    int energyUnits;
    double energyStored;
    double energyConsumed;

public:
    Energy();
    void supplyEnergy(int amount);
    double getEnergyStored();
    void produceEnergy(double amount);
    void consumeEnergy(double amount);
};

#endif 