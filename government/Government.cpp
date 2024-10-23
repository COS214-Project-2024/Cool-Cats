#include "Government.h"
#include <iostream>

Government::Government() : taxRate(0.10), budget(10000) {}

void Government::setTaxRate(float newRate) {
    taxRate = newRate;
    std::cout << "Tax rate set to: " << taxRate << std::endl;
    budget += taxRate * 1000; 
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

void Government::get(){
     std::cout<<"getting government\n";
}

void Government::set(){
     std::cout<<"setting government\n";
}