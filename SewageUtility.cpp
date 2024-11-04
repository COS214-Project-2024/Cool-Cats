#include "SewageUtility.h"


SewageUtility::SewageUtility(Structure* s) : Utilities(s){

}

void SewageUtility::processRequest(const std::string& request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'S'){
            condition = true;
        }
    }

    if (condition) {
        treatSewage();
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

