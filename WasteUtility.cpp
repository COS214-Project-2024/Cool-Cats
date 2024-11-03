#include "WasteUtility.h"


WasteUtility::WasteUtility(){

}

void WasteUtility::processRequest(const std::string& request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'B'){
            condition = true;
        }
    }
    if (condition) {
        std::cout << "WasteUtility: Handling garbage collection.\n";
    }

    if(next){
        cout << "going on to next" << endl;
        next->processRequest(request);
    }
}

void WasteUtility::collectWaste(){
    cout << "collecting waste" << endl;
}

