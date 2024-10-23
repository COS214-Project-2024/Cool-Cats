#include <iostream>
#include "Transportation.h"
#include "Transport.h"
#include "PublicTransport.h"
#include "PublicVehicle.h"
#include "Bus.h"

#include "RoadSubject.h"
#include "Road.h"
#include "RoadState.h"
#include "UnderConstruction.h"
#include "Working.h"
#include "ConcreteObserver.h"


using namespace std;

void testingTransport(){
    
    
}

int main(){

    // PublicVehicle* bus1 = new Bus();
    // bus1->setName("Test bus 1");
    // bus1->setCapacity(20);// remember to make bus logic for when there are more people than the bus can handle to then subtract and make the res wait
    // bus1->setMaxCapacity(50);
    // //Idea, instead of get name make a get details function to return the vehicles details about capacity and name;
    // bus1->isFull();
    // // Transport* testPublic = new PublicTransport(bus1);
    // // Transportation* transport1 = new Transportation(testPublic);
    // // transport1->travel();
    

    //cout << "Hello world" << endl;
    //testingTransport();



    Road* road = new Road("123 Street", 111, 222, 333);
    RoadSubject* Road = road;
    RoadState* UC = new UnderConstruction();
    RoadState* work = new Working();
    PublicVehicle* bus = new Bus();
    Transport* publicT = new PublicTransport(bus);
    Transportation* trans1 = new ConcreteObserver(road, publicT);


    std::cout << "This road's details are: "<< endl
    << "Street name: " << Road->getName() << endl 
    << "Maintenance cost: " << Road->getMaintenanceCost() << endl 
    << "Resource consumption: "<< Road->getResourceConsumption() << endl 
    << "Citizen Satisfaction: "<< Road->getCitizenSatisfactionImpact() << std::endl;

    Road->attach(trans1);
    road->setState(work);
    //road->checkState();
    trans1->travel();
    std::cout << "Oh no, something went wrong" << std::endl;
    road->setState(UC);
    trans1->travel();


    
    
    

    return 0;
}

