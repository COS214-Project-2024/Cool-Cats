#include"TaxMemento.h"

TaxMemento::TaxMemento(Taxes* s){
    state = s;
}

TaxMemento::~TaxMemento(){
    std::cout<<"destroyed taxMemento\n";
}

 TaxMemento* TaxMemento::getState(){
  return this;
}

void TaxMemento::setState(Taxes* s){
 state =s;
}