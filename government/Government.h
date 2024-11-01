#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include"TaxMemento.h"
#include <string>
#include <vector>

class Government  {
private:
    Taxes* tax;
    float budget;
    std::vector<TaxMemento*> taxMementos;

public:
    Government();
    ~Government();
    void setTaxRate(float newRate);
    void setTaxRate(Taxes* newRate);
    Taxes* getTax();
    void implementPolicy(const std::string& policy);
    float getBudget() const;
    void allocateBudget(float amount);
    void collection();
    void storeMemento(TaxMemento* one);
    TaxMemento* getMemento();
};

#endif