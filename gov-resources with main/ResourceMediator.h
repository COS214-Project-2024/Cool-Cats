#ifndef RESOURCEMEDIATOR_H
#define RESOURCEMEDIATOR_H
#include <string>

class ResourceMediator {
public:
    virtual void coordinateResources(const std::string& projectType, int materialsAmount, int energyAmount, int waterAmount) = 0;
};

#endif
