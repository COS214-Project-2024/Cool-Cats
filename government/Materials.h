#ifndef MATERIALS_H
#define MATERIALS_H

#include "Government.h"

class Materials : public Government {
private:
    double materialsAvailable;
    double materialsUsed;

public:
    Materials(ResourceMediator* mediator);
    
    void supplyMaterials(double amount);
    void useMaterials(double amount);
    double getMaterialsAvailable() const;
};

#endif
