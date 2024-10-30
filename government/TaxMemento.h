#ifndef TAXMEMENTO
#define TAXMEMENTO
#include "Taxes.h"
#include<vector>


class TaxMemento {
private:
    Taxes* state;


public:
    TaxMemento(Taxes* s);
    virtual ~TaxMemento() ;
    TaxMemento* getState();
    void setState(Taxes* s);
    
};

#endif