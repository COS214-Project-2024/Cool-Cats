#include"TaxMemento.h"

/// @brief Constructs a TaxMemento object that saves the state of a Taxes object.
/// @param s A pointer to the Taxes object to save the state of.
TaxMemento::TaxMemento(Taxes* s){
    state = new Taxes(s->getTaxRate()) ;
}

/// @brief Destroys the TaxMemento object and frees allocated memory.
TaxMemento::~TaxMemento(){
    delete state;
}

 /// @brief Gets the saved state of the Taxes object.
/// @return A pointer to the saved Taxes object.
 Taxes* TaxMemento::getState(){
  return state;
  //state = nullptr;
}

/// @brief Sets the state of the Taxes object in the memento.
/// @param s A pointer to the Taxes object whose state is to be saved.
void TaxMemento::setState(Taxes* s){
 if (state != nullptr) {
        delete state;  // Delete the previous state to prevent memory leaks
    }
    state = new Taxes(s->getTaxRate());
}
