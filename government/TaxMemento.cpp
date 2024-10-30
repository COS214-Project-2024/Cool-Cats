#include"TaxMemento.h"
/// @brief 
/// @param s 
TaxMemento::TaxMemento(Taxes* s){
    state = s;
}
/// @brief 
TaxMemento::~TaxMemento(){
    std::cout<<"destroyed taxMemento\n";
}
 /// @brief 
 /// @return 
 TaxMemento* TaxMemento::getState(){
  return this;
}
/// @brief 
/// @param s 
void TaxMemento::setState(Taxes* s){
 state =s;
}