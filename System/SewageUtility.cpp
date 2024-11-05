#include "SewageUtility.h"

/// @brief This is the constructor for sewage utility
/// @param s This parameter is a pointer to a structure. Since each structure will need utilites this parameter all utilities needed will be added to this sturcure passed in
SewageUtility::SewageUtility(Structure* s) : Utilities(s){

}

/// @brief It checks whether the passed in parameter contains a 'S' and if it does it will allow this to function in the chain to be handled by this class. WHich in this case it is Sewage utility.
/// @param request For this function to be used a S has to be present in the string passed in and if so then we can call extract water
void SewageUtility::processRequest(const std::string& request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'S'){
            condition = true;
        }
    }

    if (condition) {
        treatSewage();
        //std::cout << "SewageUtility: Handling sewage overflow.\n";
    } 
    if(next){
        //cout << "going on to next" << endl;
        next->processRequest(request);
    }
}

/// @brief Disposes of all the sewage in the structure
void SewageUtility::treatSewage(){
    struc->setSewageAmount(0);
    cout << "treating sewage" << endl;
}

