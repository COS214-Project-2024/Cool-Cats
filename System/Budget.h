#ifndef BUDGET_H
#define BUDGET_H

#include "Government.h"

class Budget : public Government {
private:
    double budgetAmount;

public:
    Budget(ResourceMediator* mediator);
    
    void requestBudget(double amount);
    void allocateBudget(double amount);
    double getBudgetAmount() const;
};

#endif
