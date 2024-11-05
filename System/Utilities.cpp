#include "Utilities.h"


/// @brief this is construtor for utilites. Its needed as from this one we will be able to set the next thing a chain
/// @param s This parameter is a pointer to a structure. Since each structure will need utilites this parameter all utilities needed will be added to this sturcure passed in
Utilities::Utilities(Structure* s){
    struc = s;
}
/// @brief This function will set the next handler in the chain 
/// @param nextHandler This sets the next item in the chain
void Utilities::setNext(Utilities* nextHandler){
    next = nextHandler;
}

/// @brief Thsi function checks if there is a next handler in the chain and if there is checks if it can process the request, if not it passes it on to the next item in the chain
/// @param request This is a string of characters where each character represents a specific request which will be determined by this function
void Utilities::processRequest(const std::string& request){
    if(next){
        next->processRequest(request);
    }
}
