#include "Utilities.h"

Utilities::Utilities(){

}

void Utilities::setNext(Utilities* nextHandler){
    next = nextHandler;
}

void Utilities::processRequest(const std::string& request){
    if(next){
        next->processRequest(request);
    }
}
