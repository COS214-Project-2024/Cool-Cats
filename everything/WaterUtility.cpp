// #include "WaterUtility.h"

// WaterUtility::WaterUtility(){
//     storageUnits = 10000;
//     capacity = 50;
//     puritylevels = 2;
// }

// void WaterUtility::processRequest(const std::string &request){
//     if (request == "GetWater"){
//         cout << "WaterUtility: Handling water problem";
//         extractWater();
//     }
//     else{
//         std::cout << "WaterUtility: cant handle, passing the quest along";
//         Utilities::processRequest(request);
//     }
// }

// void WaterUtility::extractWater(){
//     if(water->waterStored() < 100){
//         water->produceWater(200);

//     }
//     capacity += 100;
//     puritylevels = 2;
//     water->consumeWater(100);
// }

// void WaterUtility::manageDistribution(const std::string &buildingType, int amount){
//     if(amount > capacity){
//         extractWater();
//         manageDistribution(buildingType, amount);
//     }
//     capacity = capacity - amount;
//     cout << "Water of " << amount << " has been distributed to: " << buildingType; 
    
// }

// void WaterUtility::purifyWater(){
//     puritylevels++;
// }

