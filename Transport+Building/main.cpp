#include <iostream>
#include <vector>
#include <array>
#include <map>


#include "RoadSubject.h"
#include "Road.h"
#include "RoadState.h"
#include "UnderConstruction.h"
#include "Working.h"
#include "ConcreteObserver.h"

#include "Transportation.h"
#include "Transport.h"

#include "PublicTransport.h"
#include "PublicVehicle.h"
#include "Bus.h"
#include "Taxi.h"

#include "TrainTransport.h"
#include "TrainVehicle.h"
#include "Metro.h"
#include "Tram.h"
#include "Freight.h"

#include "AirportTransport.h"
#include "AirVehicle.h"
#include "Passenger.h"
#include "Cargo.h"

//Building imports
#include "Structure.h"
#include "StructureGroup.h"
#include "StructureDecorator.h"
#include "CStructIterator.h"
#include "SatisfactionEnhancer.h"
#include "MaintenanceCostReducer.h"
#include "ResourceEfficiencyEnhancer.h"
#include "BasicStructure.h"
#include "StructureIterator.h"



using namespace std;


void testingTransportationSystem(){

    //creating road
    Road* road = new Road("123 Street");
    RoadSubject* Road = road;

    //creating road states
    RoadState* UC = new UnderConstruction();
    RoadState* work = new Working();

    //creating vehicles to travel down that road
    PublicVehicle* bus = new Bus("Na");
    Transport* publicT = new PublicTransport(bus);

    //creating transportation observer that monitors that specific road
    Transportation* trans1 = new ConcreteObserver(road, publicT);


    std::cout << "This road's details are: "<< endl
    << "Street name: " << Road->getName() << endl;

    //attaching the observer to the road
    Road->attach(trans1);
    //setting current road state to working and ready to travel on
    road->setState(work);
    //traveling
    trans1->travel();
    std::cout << "Oh no, something went wrong" << std::endl;
    //changing current road state to under construction and unable to be traveled on
    road->setState(UC);
    //notifying all observers
    Road->notify();
    //traveling
    trans1->travel();
}
vector<StructureGroup*> arr;
vector<PublicTransport*> PT; // To hold all the Public transport
vector<TrainTransport*> TT; // To hold all the Train transport
vector<AirportTransport*> AT; // To hold all the Air transport
map<string, pair<vector<Road*>, vector<RoadSubject*>>> cityRoads; // To assign a road and roadSubject to a specific city group name

void createPublicType(int type, string name){
    switch (type)
    {
        case 1:
            PT.push_back((new PublicTransport(new Bus(name))));
            std::cout << "Added Successfully" << std::endl;
            break;
        case 2:
            PT.push_back(new PublicTransport(new Taxi(name)));
            std::cout << "Added Successfully" << std::endl;
            break;
        default:
            std::cout << "Invalid Public transport type" << std::endl;
    }
} 
void createTrainType(int type, string name){
    switch (type)
    {
        case 1:
            TT.push_back(new TrainTransport(new Metro(name)));
            std::cout << "Added Successfully" << std::endl;
            break;
        case 2:
            TT.push_back(new TrainTransport(new Tram(name)));
            std::cout << "Added Successfully" << std::endl;
            break;
        case 3:
            TT.push_back(new TrainTransport(new Freight(name)));
            std::cout << "Added Successfully" << std::endl;
            break;
        default:
            std::cout << "Invalid Train Transport Type" << std::endl;;
    }
} 
void createAirportType(int type, string name){
    switch (type)
    {
        case 1:
            AT.push_back(new AirportTransport(new Passenger(name)));
            std::cout << "Added Successfully" << std::endl;
            break;
        case 2:
            AT.push_back(new AirportTransport(new Cargo(name)));
            std::cout << "Added Successfully" << std::endl;
            break;
        default:
            std::cout << "Invalid Airport Transport Type" << std::endl;;
    }
}
void createRoad(const std::string& roadName, const std::string& structureGroupName) {
    Road* road = new Road(roadName);
    RoadSubject* rs = road;

    auto it = cityRoads.find(structureGroupName);
    if (it != cityRoads.end()) {
        it->second.first.push_back(road);    // Add Road* to the first vector
        it->second.second.push_back(rs);     // Add RoadSubject* to the second vector
    } else {
        // Structure group does not exist; create a new entry with initialized vectors
        cityRoads[structureGroupName] = { {road}, {rs} };
    }

    std::cout << "Road " << roadName << " added to structure group: " << structureGroupName << "\n";
}

void createInCityTransportRoute(int TransType, string CityStruct, BasicStructure* starting, BasicStructure* end, string transName){
    switch(TransType){
        case 1:
            for (PublicTransport* PublicTrans : PT) {
                if(PublicTrans->getVehicle()->getName() == transName){
                    
                }
            }
    }
}






int main(){


    std::cout << "Hello World" << std::endl;
    return 0;
}

