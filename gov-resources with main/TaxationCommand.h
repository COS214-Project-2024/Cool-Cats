#ifndef TAXATIONCOMMAND_H
#define TAXATIONCOMMAND_H
#include "Command.h"
#include "Government.h"

class TaxationCommand : public Command {
private:
    Government& government;
    float taxRate;

public:
    TaxationCommand(Government& govt, float rate);
    void execute() override;
};

#endif 