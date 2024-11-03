#include "BudgetAllocationCommand.h"
#include "Government.h"
#include <iostream>

void BudgetAllocationCommand::execute() {
    std::cout << "Allocating budget of " << budgetAmount << "." << std::endl;
    government->allocateBudget(budgetAmount);
    double currentSatisfaction = myCitizen->getSatisfaction();
    myCitizen->setSatisfaction(currentSatisfaction + budgetAmount * 0.05);
}

void BudgetAllocationCommand::undo() {
    std::cout << "Reverting budget allocation of " << budgetAmount << "." << std::endl;
    // government->revertBudget(budgetAmount);
    double currentSatisfaction = myCitizen->getSatisfaction();
    myCitizen->setSatisfaction(currentSatisfaction - budgetAmount * 0.05);
}
