#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include"GovernmentColleague.h"
#include"TaxMemento.h"
#include <string>
#include <vector>

class Government : public GovernmentColleague {
private:
    float taxRate;
    float budget;
    std::vector<TaxMemento*> taxMementos;

public:
    Government();
    void setTaxRate(float newRate);
    void implementPolicy(const std::string& policy);
    float getBudget() const;
    void allocateBudget(float amount);
    void get();
    void set();
};

#endif