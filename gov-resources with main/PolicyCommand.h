#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H
#include "Command.h"
#include "Government.h"
#include <string>

class PolicyCommand : public Command {
private:
    Government& government;
    std::string policy;

public:
    PolicyCommand(Government& govt, const std::string& policyName);
    void execute() override;
};

#endif