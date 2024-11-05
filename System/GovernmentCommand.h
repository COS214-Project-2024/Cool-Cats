#ifndef GOVERNMENTCOMMAND_H
#define GOVERNMENTCOMMAND_H
#include "Citizen.h"

class GovernmentCommand {
protected:
    Citizen* myCitizen;


public:
    GovernmentCommand(Citizen* citizen = nullptr) : myCitizen(citizen) {}
    virtual ~GovernmentCommand() {}

    virtual void execute() = 0;
    virtual void undo() = 0;
};

#endif 
