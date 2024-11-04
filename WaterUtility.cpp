#include "WaterUtility.h"

WaterUtility::WaterUtility(Structure* s) : Utilities(s){
    storageUnits = 10000;
    capacity = 50;
    puritylevels = 2;
}

void WaterUtility::processRequest(const std::string &request){
    bool condition = false;
    for(char ch : request) {
        if(ch == 'W'){
            condition = true;
        }
    }
    if (condition){
        cout << "WaterUtility: Handling water problem";
        extractWater();
    }
    if(next){
        cout << "going on to next" << endl;
        next->processRequest(request);
    }
}

void WaterUtility::extractWater(){
    capacity += 100;
    struc->setAvailableWater(capacity);
    // if(water->waterStored() < 100){
    //     water->produceWater(200);

    // }
    // capacity += 100;
    // puritylevels = 2;
    // water->consumeWater(100);
}

void WaterUtility::manageDistribution(const std::string &buildingType, int amount){
    if(amount > capacity){
        extractWater();
        manageDistribution(buildingType, amount);
    }
    capacity = capacity - amount;
    cout << "Water of " << amount << " has been distributed to: " << buildingType; 
    
}

void WaterUtility::purifyWater(){
    puritylevels++;
}

