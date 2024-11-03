#include "PolicyImplementationCommand.h"
#include "Government.h"
#include <iostream>

void PolicyImplementationCommand::execute() {
    std::cout << "Implementing policy: " << policyDetails << std::endl;
    government->enforcePolicy(policyDetails);
    double currentSatisfaction = myCitizen->getSatisfaction();
    if (policyDetails == "healthcare") {
        myCitizen->setSatisfaction(currentSatisfaction + 10.0);
    } else if (policyDetails == "education") {
        myCitizen->setSatisfaction(currentSatisfaction + 8.0);
    }
}

void PolicyImplementationCommand::undo() {
    std::cout << "Reverting policy: " << policyDetails << std::endl;
    government->revokePolicy(policyDetails);
    double currentSatisfaction = myCitizen->getSatisfaction();
    if (policyDetails == "healthcare") {
        myCitizen->setSatisfaction(currentSatisfaction - 10.0);
    } else if (policyDetails == "education") {
        myCitizen->setSatisfaction(currentSatisfaction - 8.0);
    }
}