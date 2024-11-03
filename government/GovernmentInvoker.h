#ifndef GOVERNMENTINVOKER_H
#define GOVERNMENTINVOKER_H
#include "GovernmentCommand.h"
#include "GovernmentInvoker.h"
#include <memory>



class GovernmentInvoker {
private:
    std::unique_ptr<GovernmentCommand> currentCommand;

public:
    void setCommand(std::unique_ptr<GovernmentCommand> command);
    void executeCommand();
};

#endif