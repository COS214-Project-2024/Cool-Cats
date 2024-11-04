#include "PowerUtility.h"


PowerUtility::PowerUtility(Structure* s) : Utilities(s) {

}

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

void PowerUtility::generatePower(){


    powerMega += 50;
    struc->setKilowatts(powerMega);
}