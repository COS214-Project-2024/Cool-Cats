#include "PowerUtility.h"

/// @brief This is the constructor for power utility
/// @param s This parameter is a pointer to a structure. Since each structure will need utilites this parameter all utilities needed will be added to this sturcure passed in
PowerUtility::PowerUtility(Structure* s) : Utilities(s) {

}

/// @brief It checks whether the passed in parameter contains a 'P' and if it does it will allow this to function in the chain to be handled by this class. WHich in this case it is waste utility.
/// @param request For this function to be used a P has to be present in the string passed in and if so then we can call extract water
void PowerUtility::processRequest(const std::string& request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'P'){
            condition = true;
        }
    }

    if(condition){
        //std::cout << "PowerUtility : Handling Power Usage.\n";
        generatePower();
    }
    if(next){
        //cout << "going on to next" << endl;
        next->processRequest(request);
    }

}

/// @brief Adds power to the sturcture
void PowerUtility::generatePower(){


    powerMega += 50;
    struc->setKilowatts(powerMega);
}