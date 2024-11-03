#include <iostream>
#include <vector>
#include <array>

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

#include <tuple>


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

vector<PublicTransport*> PT;
vector<TrainTransport*> TT;
vector<AirportTransport*> AT;

vector<RoadSubject*> RS;
vector<Road*> R;
array<vector<Transport*>,3> transportArray;

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
void createRoad(string name){
    Road* road = new Road(name);
    R.push_back(road);
    RoadSubject* rs = road;
    RS.push_back(rs);
    std::cout << "Road Added Successfully" << std::endl;
}

void createTransportLine(int numRoads, int transportTypeIndex, int mainTransport ){
    
}


int main(){


    std::cout << "Hello World" << std::endl;
    return 0;
}

