#include "WasteUtility.h"

/// @brief This is the constructor for waste utility
/// @param s This parameter is a pointer to a structure. Since each structure will need utilites this parameter all utilities needed will be added to this sturcure passed in
WasteUtility::WasteUtility(Structure* s) : Utilities(s){

}

/// @brief It checks whether the passed in parameter contains a 'B' and if it does it will allow this to function in the chain to be handled by this class. WHich in this case it is waste utility.
/// @param request For this function to be used a B has to be present in the string passed in and if so then we can call extract water
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
/// @brief Disposes the waste in the sturcture
void WasteUtility::collectWaste(){
    struc->setWasteAmount(0);
}

