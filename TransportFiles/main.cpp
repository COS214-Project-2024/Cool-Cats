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

void testingTransportationSystem(){

    //creating road
    Road* road = new Road("123 Street", 111, 222, 333);
    RoadSubject* Road = road;

    //creating road states
    RoadState* UC = new UnderConstruction();
    RoadState* work = new Working();

    //creating vehicles to travel down that road
    PublicVehicle* bus = new Bus();
    Transport* publicT = new PublicTransport(bus);

    //creating transportation observer that monitors that specific road
    Transportation* trans1 = new ConcreteObserver(road, publicT);


    std::cout << "This road's details are: "<< endl
    << "Street name: " << Road->getName() << endl 
    << "Maintenance cost: " << Road->getMaintenanceCost() << endl 
    << "Resource consumption: "<< Road->getResourceConsumption() << endl 
    << "Citizen Satisfaction: "<< Road->getCitizenSatisfactionImpact() << std::endl;

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

int main(){
    testingTransportationSystem();
    return 0;
}

