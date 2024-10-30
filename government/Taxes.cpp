#include"Taxes.h"
#include"TaxMemento.cpp"
#include<iostream>

Taxes::Taxes(float one ){
    taxRate = one;
    //utilityCharge = two;
}

Taxes::~Taxes(){
    std::cout<<"destroying Taxes\n";
}


TaxMemento* Taxes::createMemento(){
return  new TaxMemento(this);


}

void Taxes::setTaxRate(float n){
    taxRate = n;
}
float Taxes::getTaxRate(){
    return taxRate;
}
void Taxes::collection(){
    std::cout<<"collect taxes\n";
}

void Taxes::allocation(){
    std::cout<<"allocate taxes\n";
}

void Taxes::impact(){
  std::cout<<"impact on citizen\n";
}