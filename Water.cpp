#include "Water.h"

Water::Water(ResourceMediator* mediator)
    : Government(mediator), waterProduced(0), waterConsumed(0) {}

void Water::produceWater(double amount) {
    waterProduced += amount;
    storeWater(amount);
}

void Water::consumeWater(double amount) {
    if (waterProduced >= amount) {
        waterConsumed += amount;
        waterProduced -= amount;
    }
}

void Water::storeWater(double amount) {
    waterProduced += amount;
}

double Water::waterStored() const {
    return waterProduced - waterConsumed;
}
