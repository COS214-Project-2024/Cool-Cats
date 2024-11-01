#ifndef TAXMEMENTO
#define TAXMEMENTO
#include "Taxes.h"
#include<vector>


class TaxMemento {
private:
    Taxes* state;
    TaxMemento(Taxes* s);
    friend class Taxes;
public:
   
    virtual ~TaxMemento() ;
    Taxes* getState();
    void setState(Taxes* s);
    
    
};

#endif