#include <iostream>
#include "Transportation.h"
#include "Transport.h"
#include "PublicTransport.h"
#include "PublicVehicle.h"
#include "Bus.h"


using namespace std;

int main(){

    cout << "Hello world" << endl;

    PublicVehicle* bus1 = new Bus();
    bus1->setName("Test bus 1");
    bus1->setCapacity(20);// remember to make bus logic for when there are more people than the bus can handle to then subtract and make the res wait
    bus1->setMaxCapacity(50);
    //Idea, instead of get name make a get details function to return the vehicles details about capacity and name;
    bus1->isFull();
    Transport* testPublic = new PublicTransport(bus1);
    Transportation* transport1 = new Transportation(testPublic);
    transport1->travel();
    return 0;
}