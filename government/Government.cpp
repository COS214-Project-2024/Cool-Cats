#include "Government.h"
#include <iostream>

Government::Government()  {
    budget = 10000;
    tax->setTaxRate(0.10);
}

void Government::setTaxRate(float newRate) {
    tax->setTaxRate(newRate);
    std::cout << "Tax rate set to: " << tax->getTaxRate() << std::endl;
    budget += tax->getTaxRate() * 1000; 
}

void Government::implementPolicy(const std::string& policy) {
    std::cout << "Implementing policy: " << policy << std::endl;
}

float Government::getBudget() const {
    return budget;
}

void Government::allocateBudget(float amount) {
    if (amount > budget) {
        std::cout << "Insufficient budget to allocate." << std::endl;
    } else {
        budget -= amount;
        std::cout << "Allocated " << amount << " to city services. Remaining budget: " << budget << std::endl;
    }
}


void Government::storeMemento(TaxMemento* One){
     if (One) {  
            taxMementos.push_back(One);  
        }
}

TaxMemento* Government::getMemento(){
if (taxMementos.empty()) {
            return nullptr;  
        }
        return taxMementos.back();

}