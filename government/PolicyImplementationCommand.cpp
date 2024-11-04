#include "PolicyImplementationCommand.h"
#include "Government.h"
#include <iostream>

void PolicyImplementationCommand::execute() {
    std::cout << "Implementing policy: " << policyDetails << std::endl;
    government->enforcePolicy(policyDetails);
    if (myCitizen) {
        double currentSatisfaction = myCitizen->getSatisfaction();
        double newSatisfaction = currentSatisfaction;
        if (policyDetails == "healthcare") {
            newSatisfaction += 10.0;
        } else if (policyDetails == "education") {
            newSatisfaction += 8.0;
        }
        myCitizen->setSatisfaction(newSatisfaction);
        std::cout << "Satisfaction increased by " << newSatisfaction - currentSatisfaction << std::endl;
    }
}

void PolicyImplementationCommand::undo() {
    std::cout << "Reverting policy: " << policyDetails << std::endl;
    government->revokePolicy(policyDetails);
    if (myCitizen) {
        double currentSatisfaction = myCitizen->getSatisfaction();
        double newSatisfaction = currentSatisfaction;
        if (policyDetails == "healthcare") {
            newSatisfaction -= 10.0;
        } else if (policyDetails == "education") {
            newSatisfaction -= 8.0;
        }
        myCitizen->setSatisfaction(newSatisfaction);
        std::cout << "Satisfaction decreased by " << currentSatisfaction - newSatisfaction << std::endl;
    }
}