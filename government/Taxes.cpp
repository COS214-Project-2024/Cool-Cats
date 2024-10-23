#include"Taxes.h"
#include"TaxMemento.cpp"

Taxes::Taxes(float one , float two){
    taxRate = one;
    utilityCharge = two;
}

Taxes::~Taxes(){
    std::cout<<"destroying Taxes\n";
}
void Taxes::get(){
     std::cout<<"getting Taxes\n";
}
 void Taxes::set(){
     std::cout<<"setting Taxes\n";
}

TaxMemento* Taxes::createMemento(){
TaxMemento* one = new TaxMemento();
return one;

}

void Taxes::setMemento(TaxMemento* s){
    std::cout<<"set TaxMemento for Taxes class\n";
}