#include "WasteUtility.h"


WasteUtility::WasteUtility(){

}

void WasteUtility::processRequest(const std::string& request){
    if (request == "garbage collection") {
        std::cout << "WasteUtility: Handling garbage collection.\n";
    } else {
        std::cout << "WasteUtility: Can't handle, passing the request along.\n";
        Utilities::processRequest(request); // Pass to the next handler
    }
}

void WasteUtility::collectWaste(){
    cout << "collecting waste" << endl;
}

