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
map<string, vector<Transportation*>> transLines;


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
    RoadState* UC = new UnderConstruction();
    Road* road = new Road(roadName);
    RoadSubject* rs = road;
    road->setState(UC);

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

int structureIndex(StructureGroup* group, Structure* name){
    int i = 0;
    StructureIterator* iterate = group->createIterator();
    while(iterate->isDone() == false){
        if(iterate->currentItem() == name){
            return i;
        }
        iterate->next();
        i++;
    }
    return -1;
    
}

void createInCityTransportRoute(int TransType, string CityName, BasicStructure* starting, BasicStructure* ending, string transName, string routeName){
    switch(TransType){
        //Public Transport
        case 1:
            for (PublicTransport* PublicTrans : PT) {
                if(PublicTrans->getVehicle()->getName() == transName){
                    for (StructureGroup* Cities : arr){
                        if(Cities->getName() == CityName){
                            int startIdx = structureIndex(Cities, starting);
                            int endIdx = structureIndex(Cities, ending);
                            //std::cout << "We here" << std::endl;
                            if (startIdx != -1 && endIdx != -1 && cityRoads.count(CityName)) {
                                auto& roads = cityRoads[CityName].first;
                                auto& roadSubjects = cityRoads[CityName].second;
                                vector<Transportation*> observers;
                                vector<RoadSubject*> subjects;
                                
                                if (startIdx <= endIdx) {
                                    for (int i = startIdx; i <= endIdx; ++i) {
                                        observers.push_back(new ConcreteObserver(roads[i],PublicTrans));
                                        roadSubjects[i]->notify();
                                    }
                                } else {
                                    for (int i = startIdx; i >= endIdx; --i) {
                                        observers.push_back(new ConcreteObserver(roads[i],PublicTrans));
                                        roadSubjects[i]->notify();
                                    }
                                }
                                transLines.insert({routeName, observers});
                            }
                        }
                        else{
                            std::cout << "No such City name" << std::endl;
                            return;
                        }
                    }
                }
                else{
                    std::cout << "No such Public Transport Name" << std::endl;
                    return;
                }
            }
            break;
            //Train transport
            case 2:
                for (TrainTransport* TrainTrans : TT) {
                    if(TrainTrans->getVehicle()->getName() == transName){
                        for (StructureGroup* Cities : arr){
                            if(Cities->getName() == CityName){
                                int startIdx = structureIndex(Cities, starting);
                                int endIdx = structureIndex(Cities, ending);
                                if (startIdx != -1 && endIdx != -1 && cityRoads.count(CityName)) {
                                    auto& roads = cityRoads[CityName].first;
                                    auto& roadSubjects = cityRoads[CityName].second;
                                    vector<Transportation*> observers;
                                    vector<RoadSubject*> subjects;
                                    if (startIdx <= endIdx) {
                                        for (int i = startIdx; i <= endIdx; ++i) {
                                            observers.push_back(new ConcreteObserver(roads[i],TrainTrans));
                                            roadSubjects[i]->notify();
                                        }
                                    } else {
                                        for (int i = startIdx; i >= endIdx; --i) {
                                            observers.push_back(new ConcreteObserver(roads[i],TrainTrans));
                                            roadSubjects[i]->notify();
                                        }
                                    }
                                    transLines.insert({routeName, observers});
                                }
                            }
                            else{
                                std::cout << "No such City name" << std::endl;
                                return;
                            }
                        }
                    }
                    else{
                        std::cout << "No such Train Transport Name" << std::endl;
                        return;
                    }
                }
            break;
            default:
            std::cout << "Incorrect Transport type" << std::endl;
            break;
            
    }
}

void travelRoute(string routeName){
    vector<Transportation*> travelLine = transLines.find(routeName)->second;
    for(int i = 0; i < travelLine.size(); i++){
        travelLine[i]->travel();
    }
}


int main(){

    BasicStructure* school0 = new BasicStructure("School0", 'c', 500);
    BasicStructure* school1 = new BasicStructure("School1", 'c', 500);
    BasicStructure* school2 = new BasicStructure("School2", 'c', 500);

    StructureGroup* city1 = new StructureGroup("City1");
    city1->add(school0);
    city1->add(school1);
    city1->add(school2);
    arr.push_back(city1);

    createPublicType(1, "City-2-City");
    createTrainType(1, "Gautrain");
    createAirportType(1, "Boeing 747");

    createRoad("123 Lunnin Street", "City1");
    createRoad("284 KepmtonPark", "City1");
    createRoad("285 Shxta road", "City1");

    createInCityTransportRoute(1,"City1",school0,school2,"City-2-City","TestRoute");
    travelRoute("TestRoute");


    std::cout << "Hello World" << std::endl;
    return 0;
}

