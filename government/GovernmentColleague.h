#ifndef GOVERNMENTCOLLEAGUE
#define GOVERNMENTCOLLEAGUE
#include<iostream>
class GovernmentMediator;

class GovernmentColleague {
private:
    GovernmentColleague* mediator;
public:
    GovernmentColleague(){mediator = nullptr;}
    virtual ~GovernmentColleague() {delete mediator;}
    virtual void get() = 0;
    virtual void set() = 0;
};

#endif