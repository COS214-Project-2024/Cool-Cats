#include "SewageUtility.h"


SewageUtility::SewageUtility(BasicStructure* s) : Utilities(s){

}

void SewageUtility::processRequest(const std::string& request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'P'){
            condition = true;
        }
    }

    if (condition) {
        std::cout << "SewageUtility: Handling sewage overflow.\n";
    } 
    if(next){
        cout << "going on to next" << endl;
        next->processRequest(request);
    }
}

void SewageUtility::treatSewage(){
    struc->setSewageAmount(0);
}

