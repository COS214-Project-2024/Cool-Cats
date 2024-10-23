#ifndef TAXES
#define TAXES
#include "GovernmentColleague.h"
class TaxMemento;

class Taxes: public GovernmentColleague {
private:
    float taxRate;
    float utilityCharge;


public:
    Taxes(float one, float two);
    virtual ~Taxes() ;
    void collection();
    void allocation();
    void impact() ;
    virtual void get() ;
    virtual void set() ;
    TaxMemento* createMemento();
    void setMemento(TaxMemento* memento);
    friend class TaxMemento;
};

#endif