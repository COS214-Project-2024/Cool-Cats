#include "WaterUtility.h"

WaterUtility::WaterUtility(Structure* s) : Utilities(s){
    capacity = 50;
}

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

void WaterUtility::extractWater(){
    capacity += 100;
    struc->setAvailableWater(capacity);
}



