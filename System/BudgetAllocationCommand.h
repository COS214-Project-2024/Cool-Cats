#ifndef BUDGET_ALLOCATION_COMMAND_H
#define BUDGET_ALLOCATION_COMMAND_H
#include "GovernmentCommand.h"

class Government;

class BudgetAllocationCommand : public GovernmentCommand {
    double budgetAmount;
    Government* government;

public:
    BudgetAllocationCommand(Citizen* citizen, double amount, Government* gov)
        : GovernmentCommand(citizen), budgetAmount(amount), government(gov) {}

    void execute() override;
    void undo() override;
};

#endif 
