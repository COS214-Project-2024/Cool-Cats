#include "Government.h"
#include "ResourceMediator.h"
#include <iostream>
#include <algorithm>

Government::Government(ResourceMediator* mediator) : taxRate(10), budget(10000), mediator(mediator) {}

Government::~Government() {
    for (auto memento : taxMementos) {
        delete memento;
    }
}

void Government::setTaxRate(int rate) {
    taxRate = rate;
    std::cout << "Tax rate set to: " << taxRate << "%" << std::endl;
}

void Government::allocateBudget(double amount) {
    if (amount > budget) {
        std::cout << "Insufficient budget to allocate." << std::endl;
    } else {
        budget -= amount;
        std::cout << "Allocated " << amount << " to city services. Remaining budget: " << budget << std::endl;
    }
}

void Government::enforcePolicy(const std::string& policy) {
    policies.push_back(policy);
    std::cout << "Enforcing policy: " << policy << std::endl;
}

void Government::requestResource(const std::string& resourceType, double amount) {
    std::cout << "Requesting " << amount << " of " << resourceType << std::endl;
    mediator->requestResource(this, resourceType, amount);
}

void Government::revokePolicy(const std::string& policy) {
     auto it = std::find(policies.begin(), policies.end(), policy);
    if (it != policies.end()) {
        policies.erase(it);
        std::cout << "Revoking policy: " << policy << std::endl;
    } else {
        std::cout << "Policy not found: " << policy << std::endl;
    }
}

void Government::supplyResource(const std::string& resourceType, double amount) {
    std::cout << "Supplying " << amount << " of " << resourceType << std::endl;
    mediator->supplyResource(this, resourceType, amount);
}

void Government::storeMemento(TaxMemento* memento) {
    taxMementos.push_back(memento);
    std::cout << "Stored tax memento." << std::endl;
}

TaxMemento* Government::getMemento() {
    if (!taxMementos.empty()) {
        TaxMemento* memento = taxMementos.back();
        taxMementos.pop_back();
        std::cout << "Retrieved tax memento." << std::endl;
        return memento;
    }
    return nullptr;
}