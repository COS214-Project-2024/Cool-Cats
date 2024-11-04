#ifndef POLICYIMPLEMENTATIONCOMMAND_H
#define POLICYIMPLEMENTATIONCOMMAND_H
#include "GovernmentCommand.h"
#include <string>
class Government;

class PolicyImplementationCommand : public GovernmentCommand {
    std::string policyDetails;
    Government* government;

public:
    PolicyImplementationCommand(Citizen* citizen, const std::string& policy, Government* gov)
        : GovernmentCommand(citizen), policyDetails(policy), government(gov) {}

    void execute() override;
    void undo() override;
};

#endif 
