#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include "ResourceMediator.h"
#include "TaxMemento.h"

class Government {
private:
    int taxRate;
    double budget;
    std::vector<std::string> policies;
    ResourceMediator* mediator;
    std::vector<TaxMemento*> taxMementos;

public:
    Government(ResourceMediator* mediator);
    ~Government();

    void setTaxRate(int rate);
    void allocateBudget(double amount);
    void enforcePolicy(const std::string& policy);
    void revokePolicy(const std::string& policy);
    
    void requestResource(const std::string& resourceType, double amount);
    void supplyResource(const std::string& resourceType, double amount);

    void storeMemento(TaxMemento* memento);
    TaxMemento* getMemento();
};

#endif