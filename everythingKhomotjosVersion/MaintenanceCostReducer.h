#ifndef MAINTENANCECOSTREDUCER_H
#define MAINTENANCECOSTREDUCER_H

#include <iostream>
#include "StructureDecorator.h"

using namespace std;

class MaintenanceCostReducer : public StructureDecorator
{
    private:
        float reductionPercentage;
    public:
        MaintenanceCostReducer(Structure* structure, float reduction);
        float getMaintenance() override;
        // void add(Structure* structure) override;
        // void remove(Structure* structure) override;
        // vector<Structure*> getChildren() override;


};

#endif