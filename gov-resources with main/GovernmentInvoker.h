#ifndef GOVERNMENTINVOKER_H
#define GOVERNMENTINVOKER_H
#include "Command.h"
#include "GovernmentInvoker.h"
#include <memory>



class GovernmentInvoker {
private:
    std::unique_ptr<Command> currentCommand;

public:
    void setCommand(std::unique_ptr<Command> command);
    void executeCommand();
};

#endif