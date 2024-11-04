#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include"AllCitizenIterator.h"
#include "ResourceMediator.h"
#include "TaxMemento.h"

class Government {
private:
    Taxes* tax;
    double budget;
    std::vector<std::string> policies;
    ResourceMediator* mediator;
    std::vector<TaxMemento*> taxMementos;

public:
    Government(ResourceMediator* mediator);
    ~Government();
    void setTaxRate(float newRate);
    void setTaxRate(Taxes* newRate);
    Taxes* getTax();
    void implementPolicy(const std::string& policy);
    float getBudget() const;
    void allocateBudget(float amount);
    void collection(AllCitizenIterator *one);
    void enforcePolicy(const std::string& policy);
    void revokePolicy(const std::string& policy);
    void requestResource(const std::string& resourceType, double amount);
    void supplyResource(const std::string& resourceType, double amount);
    void storeMemento(TaxMemento* memento);
    TaxMemento* getMemento();
};

#endif