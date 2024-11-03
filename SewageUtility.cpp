#include "SewageUtility.h"


SewageUtility::SewageUtility(){

}

void SewageUtility::processRequest(const std::string& request){
    if (request == "sewage overflow") {
        std::cout << "SewageUtility: Handling sewage overflow.\n";
    } else {
        std::cout << "SewageUtility: Can't handle, passing the request along.\n";
        Utilities::processRequest(request); // Pass to the next handler
    }
}

void SewageUtility::treatSewage(){
    cout << "treating sewage" << endl;
}

