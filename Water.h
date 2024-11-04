#ifndef WATER_H
#define WATER_H

#include "Government.h"

class Water : public Government {
private:
    double waterProduced;
    double waterConsumed;

public:
    Water(ResourceMediator* mediator);

    void produceWater(double amount);
    void consumeWater(double amount);
    void storeWater(double amount);
    double waterStored() const;
};

#endif
