#include "WaterUtility.h"
/// @brief This is the constructor for water utility
/// @param s This parameter is a pointer to a structure. Since each structure will need utilites this parameter all utilities needed will be added to this sturcure passed in
WaterUtility::WaterUtility(Structure* s) : Utilities(s){
    capacity = 50;
}
/// @brief It checks whether the passed in parameter contains a 'W' and if it does it will allow this to function in the chain to be handled by this class. WHich in this case it is water utility.
/// @param request For this function to be used a W has to be present in the string passed in and if so then we can call extract water
void WaterUtility::processRequest(const std::string &request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'W'){
            condition = true;
        }
    }
    if (condition){
        //cout << "WaterUtility: Handling water problem";
        extractWater();
    }
    if(next){
        //cout << "going on to next" << endl;
        next->processRequest(request);
    }
}

/// @brief this will increase the capacity of water available and give it to the structure
void WaterUtility::extractWater(){
    capacity += 100;
    struc->setAvailableWater(capacity);
}
