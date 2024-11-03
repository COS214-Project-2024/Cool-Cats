#include "TaxationCommand.h"
#include <iostream>

void TaxationCommand::execute() {
    std::cout << "Applying tax rate of " << taxRate << "% to citizen." << std::endl;
    government->setTaxRate(taxRate);
    double currentSatisfaction = myCitizen->getSatisfaction();
    myCitizen->setSatisfaction(currentSatisfaction - taxRate * 0.1); 
}

void TaxationCommand::undo() {
    std::cout << "Reverting tax rate of " << taxRate << "% for citizen." << std::endl;
    government->setTaxRate(0); 
    double currentSatisfaction = myCitizen->getSatisfaction();
    myCitizen->setSatisfaction(currentSatisfaction + taxRate * 0.1);
}