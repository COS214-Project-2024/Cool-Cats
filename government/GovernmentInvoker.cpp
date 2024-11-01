#include "GovernmentInvoker.h"
#include "Command.h" 

void GovernmentInvoker::setCommand(std::unique_ptr<Command> command) {
    currentCommand = std::move(command);
}

void GovernmentInvoker::executeCommand() {
    if (currentCommand) {
        currentCommand->execute();
    }
}
