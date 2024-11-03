#include "BudgetAllocationCommand.h"
#include "Government.h"
#include <iostream>

void BudgetAllocationCommand::execute() {
    std::cout << "Allocating budget of " << budgetAmount << "." << std::endl;
    government->allocateBudget(budgetAmount);
    if (myCitizen) {
        double currentSatisfaction = myCitizen->getSatisfaction();
        double newSatisfaction = currentSatisfaction + budgetAmount * 0.05;
        myCitizen->setSatisfaction(newSatisfaction);
        std::cout << "Satisfaction increased by " << newSatisfaction - currentSatisfaction << std::endl;
    }
}

void BudgetAllocationCommand::undo() {
    std::cout << "Reverting budget allocation of " << budgetAmount << "." << std::endl;
    // government->revertBudget(budgetAmount);
    if (myCitizen) {
        double currentSatisfaction = myCitizen->getSatisfaction();
        double newSatisfaction = currentSatisfaction - budgetAmount * 0.05;
        myCitizen->setSatisfaction(newSatisfaction);
        std::cout << "Satisfaction decreased by " << currentSatisfaction - newSatisfaction << std::endl;
    }
}