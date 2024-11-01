#include "PolicyCommand.h"

PolicyCommand::PolicyCommand(Government& govt, const std::string& policyName) : government(govt), policy(policyName) {}

void PolicyCommand::execute() {
    government.implementPolicy(policy);
}
