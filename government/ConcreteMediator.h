#ifndef CONCRETEMEDIATOR
#define CONCRETEMEDIATOR
#include "GovernmentMediator.h"
#include <list>
#include<iostream>

class ConcreteMediator: public GovernmentMediator {
private:
std::list<GovernmentMediator*> list;
public:
    ConcreteMediator();
    virtual ~ConcreteMediator() ;
    virtual void notify(GovernmentColleague* colleague) ;
};

#endif