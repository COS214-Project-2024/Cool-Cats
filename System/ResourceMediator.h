#ifndef RESOURCEMEDIATOR_H
#define RESOURCEMEDIATOR_H
#include <string>

class Government;

class ResourceMediator {
public:
    virtual void coordinateResources(const std::string& projectType, int materialsAmount, int energyAmount, int waterAmount) = 0;
    virtual void requestResource(Government* requester, const std::string& resourceType, double amount) = 0;
    virtual void supplyResource(Government* supplier, const std::string& resourceType, double amount) = 0;
};

#endif
