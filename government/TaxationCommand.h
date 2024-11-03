#ifndef TAXATIONCOMMAND_H
#define TAXATIONCOMMAND_H

#include "GovernmentCommand.h"
#include "Government.h"

class TaxationCommand : public GovernmentCommand {
private:
    int taxRate;
    Government* government;

public:
    TaxationCommand(Government* gov, Citizen* citizen, int rate)
        : GovernmentCommand(citizen), taxRate(rate), government(gov) {}

    void execute() override;
    void undo() override;
};

#endif