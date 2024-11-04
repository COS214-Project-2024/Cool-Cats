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
    //cout << "generatingPower";

    powerMega += 50;
    struc->setKilowatts(powerMega);
    // if(energy->getEnergyStored() < 50){
    //     energy->produceEnergy(100);
    // }
    // powerMega =+ 50;
    // energy->consumeEnergy(50);
}

void PowerUtility::transmitPower(double voltage, const std::string &areaType){
    if(voltage > powerMega){
        generatePower();
        transmitPower(voltage, areaType);
    }
    powerMega = powerMega - voltage;
    //cout << "Electricity of " << voltage << " has been transmited to: " << areaType; 
}

