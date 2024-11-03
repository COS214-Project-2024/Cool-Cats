#include <iostream>
#include <memory>
#include "Government.h"
#include "GovernmentInvoker.h"
#include "TaxationCommand.h"
#include "PolicyCommand.h"
#include "Materials.h"
#include "Energy.h"
#include "Water.h"
#include "CityResourceMediator.h"

int main() {
    Government government;
    GovernmentInvoker invoker;

    // This is the taxation command
    auto taxCommand = std::make_unique<TaxationCommand>(government, 0.15f);
    invoker.setCommand(std::move(taxCommand));
    invoker.executeCommand();

    // The is the policy command
    auto policyCommand = std::make_unique<PolicyCommand>(government, "Each household must only consume 50 000Kw of Energy");
    invoker.setCommand(std::move(policyCommand));
    invoker.executeCommand();

    government.allocateBudget(5000);

    std::cout << "--------------------------" << std::endl;

    // The resources we need for our city
    Materials materials;
    Energy energy;
    Water water;

    // Creating the mediator to coordinate resources
    CityResourceMediator resourceMediator(materials, energy, water);

    // Coordinating resources for a "New Park Project"
    resourceMediator.coordinateResources("New Park Project", 100, 50, 200);

    // Coordinating resources for a "Residential Expansion"
    resourceMediator.coordinateResources("Residential Expansion", 300, 200, 500);

    return 0;
}
