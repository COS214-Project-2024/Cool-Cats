#include "TaxMemento.h"

TaxMemento::TaxMemento(Taxes* s) : state(new Taxes(*s)) {}

TaxMemento::~TaxMemento() {
    delete state;
}

TaxMemento* TaxMemento::getState() {
    return this;
}

void TaxMemento::setState(Taxes* s) {
    *state = *s;
}
