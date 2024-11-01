#ifndef CITYRESOURCEMEDIATOR_H
#define CITYRESOURCEMEDIATOR_H
#include "Materials.h"
#include "Energy.h"
#include "Water.h"
#include "ResourceMediator.h"

class CityResourceMediator : public ResourceMediator {
private:
    Materials& materials;
    Energy& energy;
    Water& water;

public:
    CityResourceMediator(Materials& m, Energy& e, Water& w);
    void coordinateResources(const std::string& projectType, int materialsAmount, int energyAmount, int waterAmount) override;
};

#endif