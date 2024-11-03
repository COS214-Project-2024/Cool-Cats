#include "Utilities.h"
#include "BasicStructure.h"

Utilities::Utilities(BasicStructure* s){
    struc = s;
}

void Utilities::setNext(Utilities* nextHandler){
    next = nextHandler;
}

void Utilities::processRequest(const std::string& request){
    cout << "We got to the first in chain" << endl;
    if(next){
        next->processRequest(request);
    }
}
