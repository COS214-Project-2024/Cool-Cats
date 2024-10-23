#ifndef TAXMEMENTO
#define TAXMEMENTO
#include "Taxes.h"
#include<vector>


class TaxMemento {
private:
    Taxes* state;


public:
    TaxMemento();
    virtual ~TaxMemento() ;
    void getState();
    void setState(Taxes* s);
    
};

#endif