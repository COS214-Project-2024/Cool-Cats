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
    void collection();
    void allocation();
    void impact() ;
    float getTaxRate();
    void setTaxRate(float n);
    TaxMemento* createMemento();
    friend class TaxMemento;
};

#endif