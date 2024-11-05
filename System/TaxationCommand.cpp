#include "TaxationCommand.h"
#include <iostream>

void TaxationCommand::execute() {
    std::cout << "Applying tax rate of " << taxRate << "% to citizen." << std::endl;
    government->setTaxRate(taxRate);
    double currentSatisfaction = myCitizen->getSatisfaction();
    double newSatisfaction = currentSatisfaction - taxRate * 0.1;
    myCitizen->setSatisfaction(newSatisfaction);
    std::cout << "Satisfaction decreased by " << currentSatisfaction - newSatisfaction << std::endl;
}

void TaxationCommand::undo() {
    std::cout << "Reverting tax rate of " << taxRate << "% for citizen." << std::endl;
    int TaxRate = 0;
    government->setTaxRate(TaxRate);
    double currentSatisfaction = myCitizen->getSatisfaction();
    double newSatisfaction = currentSatisfaction + taxRate * 0.1;
    myCitizen->setSatisfaction(newSatisfaction);
    std::cout << "Satisfaction increased by " << newSatisfaction - currentSatisfaction << std::endl;
}