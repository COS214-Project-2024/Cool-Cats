#include"TaxMemento.h"

TaxMemento::TaxMemento(){
    std::cout<<"created taxMemento\n";
}

TaxMemento::~TaxMemento(){
    std::cout<<"destroyed taxMemento\n";
}

void TaxMemento::getState(){
  std::cout<<"get state of taxMemento\n";
}

void TaxMemento::setState(Taxes* s){
 state =s;
}