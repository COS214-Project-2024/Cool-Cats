#include"TaxMemento.h"
/// @brief 
/// @param s 
TaxMemento::TaxMemento(Taxes* s){
    state = new Taxes(s->getTaxRate()) ;
}
/// @brief 
TaxMemento::~TaxMemento(){
    delete state;
}
 /// @brief 
 /// @return 
 Taxes* TaxMemento::getState(){
  return state;
  //state = nullptr;
}
/// @brief 
/// @param s 
void TaxMemento::setState(Taxes* s){
 state =s;
}