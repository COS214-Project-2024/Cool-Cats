#ifndef GOVERNMENTMEDIATOR
#define GOVERNMENTMEDIATOR
#include "GovernmentColleague.h"

class GovernmentMediator {
public:
    virtual ~GovernmentMediator() {}
    virtual void notify(GovernmentColleague colleague) = 0;
};

#endif