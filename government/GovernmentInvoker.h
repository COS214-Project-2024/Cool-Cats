#ifndef GOVERNMENTINVOKER_H
#define GOVERNMENTINVOKER_H
#include <memory>
#include "Command.h"
#include "GovernmentInvoker.h"

class GovernmentInvoker {
private:
    std::unique_ptr<Command> currentCommand;

public:
    void setCommand(std::unique_ptr<Command> command);
    void executeCommand();
};

#endif