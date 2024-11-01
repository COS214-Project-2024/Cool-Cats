#include"Taxes.h"
#include"TaxMemento.h"
#include<iostream>
/// @brief this is the constructor of the Taxes function
/// @param one is a float that then initialize
Taxes::Taxes(float one ){ 
    taxRate = one;
    //utilityCharge = two;
}

Taxes::~Taxes(){
    
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

void Taxes::reinstateMemento(TaxMemento* n){
    taxRate = n->getState()->getTaxRate();
}