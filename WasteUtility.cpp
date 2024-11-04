#include "WasteUtility.h"


WasteUtility::WasteUtility(Structure* s) : Utilities(s){

}

void WasteUtility::processRequest(const std::string& request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'B'){
            condition = true;
        }
    }
    if (condition) {
        //std::cout << "WasteUtility: Handling garbage collection.\n";
        collectWaste();
    }

    if(next){
        //cout << "going on to next" << endl;
        next->processRequest(request);
    }
}

void WasteUtility::collectWaste(){
    struc->setWasteAmount(0);
    //cout << "collecting waste" << endl;
}

