#ifndef WATER_H
#define WATER_H

class Water {
private:
    int waterLiters;

public:
    Water();
    void supplyWater(int amount);
    void produceWater(int amount);
    void consumeWater(int amount);
    double waterStored();
};

#endif 