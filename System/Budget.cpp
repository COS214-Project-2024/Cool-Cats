#include "Budget.h"

Budget::Budget(ResourceMediator* mediator)
    : Government(mediator), budgetAmount(0) {}

void Budget::requestBudget(double amount) {
    budgetAmount += amount;
}

void Budget::allocateBudget(double amount) {
    if (budgetAmount >= amount) {
        budgetAmount -= amount;
    }
}

double Budget::getBudgetAmount() const {
    return budgetAmount;
}
