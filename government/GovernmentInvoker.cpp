#include "GovernmentInvoker.h"
#include "GovernmentCommand.h"
#include <iostream>

void GovernmentInvoker::setCommand(std::unique_ptr<GovernmentCommand> command) {
    currentCommand = std::move(command);
    std::cout << "Command set." << std::endl;
}

void GovernmentInvoker::executeCommand() {
    if (currentCommand) {
        currentCommand->execute();
        std::cout << "Command executed." << std::endl;
    } else {
        std::cout << "No command to execute." << std::endl;
    }
}