#include "PowerUtility.h"


PowerUtility::PowerUtility(){

}

void PowerUtility::processRequest(const std::string& request){
    if(request == "GeneratePower"){
        
        std::cout << "PowerUtility : Handling Power Usage.\n";
        generatePower();
    }
    else{
        std::cout << "PowerUtility: Cant handle, passing the request along. \n";
        Utilities::processRequest(request);
    }
}

void PowerUtility::generatePower(){
    
    if(energy->getEnergyStored() < 50){
        energy->produceEnergy(100);
    }
    powerMega =+ 50;
    energy->consumeEnergy(50);
}

void PowerUtility::transmitPower(double voltage, const std::string &areaType){
    if(voltage > powerMega){
        generatePower();
        transmitPower(voltage, areaType);
    }
    powerMega = powerMega - voltage;
    cout << "Electricity of " << voltage << " has been transmited to: " << areaType; 
}

