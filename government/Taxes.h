#ifndef TAXES
#define TAXES

class TaxMemento;

class Taxes {
private:
    float taxRate;
    // float utilityCharge;
    // float serviceFees;

public:
    Taxes(float one);
    virtual ~Taxes() ;
    float getTaxRate();
    void setTaxRate(float n);
    TaxMemento* createMemento();
    void reinstateMemento(TaxMemento* n);
    
};

#endif