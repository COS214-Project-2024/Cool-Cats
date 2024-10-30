#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include <string>

class Government {
private:
    float taxRate;
    float budget;

public:
    Government();
    void setTaxRate(float newRate);
    void implementPolicy(const std::string& policy);
    float getBudget() const;
    void allocateBudget(float amount);
};

#endif