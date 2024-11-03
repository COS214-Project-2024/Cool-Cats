#ifndef CITYRESOURCEMEDIATOR_H
#define CITYRESOURCEMEDIATOR_H

#include "ResourceMediator.h"
#include <string>

class CityResourceMediator : public ResourceMediator {
private:
    double energyAvailable;
    double waterAvailable;
    double materialsAvailable;
    double budget;

public:
    CityResourceMediator();
    
    void coordinateWaterUsage(double amount);
    void coordinateEnergyDistribution(double amount);
    void coordinateMaterialUsage(double amount);
    void manageBudget(double amount);

    void requestResource(Government* requester, const std::string& resourceType, double amount) override;
    void supplyResource(Government* supplier, const std::string& resourceType, double amount) override;
    void coordinateResources(const std::string& projectType, int materialsAmount, int energyAmount, int waterAmount) override;
};

#endif