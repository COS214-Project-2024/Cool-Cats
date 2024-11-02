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
void testStructure(){
    // Creating basic structures
    BasicStructure* school = new BasicStructure("School", 100, 50, 80);
    BasicStructure* hospital = new BasicStructure("Hospital", 200, 150, 95);
    BasicStructure* park = new BasicStructure("Park", 30, 10, 120);

    //structuregroup
    StructureGroup* cityStructures = new StructureGroup("City Structures");
    cityStructures->add(school);
    cityStructures->add(hospital);
    cityStructures->add(park);

    

    // Display individual structure details
    std::cout << "Individual Structures:" << std::endl;
    std::cout << "School - Maintenance: " << school->getMaintenance()
              << ", Resource Consumption: " << school->getResourceConsumption()
              << ", Citizen Satisfaction: " << school->getCitizenSatisfactionImpact() << std::endl;

    std::cout << "Hospital - Maintenance: " << hospital->getMaintenance()
              << ", Resource Consumption: " << hospital->getResourceConsumption()
              << ", Citizen Satisfaction: " << hospital->getCitizenSatisfactionImpact() << std::endl;

    std::cout << "Park - Maintenance: " << park->getMaintenance()
              << ", Resource Consumption: " << park->getResourceConsumption()
              << ", Citizen Satisfaction: " << park->getCitizenSatisfactionImpact() << std::endl;

     // Display aggregate information from the structure group
    std::cout << "\nStructure Group - " << cityStructures->getName() << ":" << std::endl;
    std::cout << "Total Maintenance: " << cityStructures->getMaintenance() << std::endl;
    std::cout << "Total Resource Consumption: " << cityStructures->getResourceConsumption() << std::endl;
    std::cout << "Total Citizen Satisfaction Impact: " << cityStructures->getCitizenSatisfactionImpact() << std::endl;

    // Step 2: Create an iterator for the structure group
    // Step 2: Create a CStructIterator for the structure group
    CStructIterator* iterator = dynamic_cast<CStructIterator*>(cityStructures->createIterator());

    if (iterator == nullptr) {
        std::cerr << "Failed to create iterator." << std::endl;
        return;
    }

    // Step 3: Use the iterator to print each structure's details
    std::cout << "Iterating through structures in " << cityStructures->getName() << ":" << std::endl;
    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        Structure* structure = iterator->currentItem();
        if (structure != nullptr) {
            std::cout << "Structure Name: " << structure->getName() << std::endl;
            std::cout << "Maintenance: " << structure->getMaintenance()
                      << ", Resource Consumption: " << structure->getResourceConsumption()
                      << ", Citizen Satisfaction: " << structure->getCitizenSatisfactionImpact() << std::endl;
        }
    }

    // Clean up allocated memory
    delete iterator;


    // Clean up allocated memory
    delete cityStructures;


}

void Decoratortest(){
    // Step 1: Create a basic structure
    BasicStructure* library = new BasicStructure("Library", 100, 50, 70);
    
    // Display the initial structure's properties
    std::cout << "Initial Structure: " << library->getName() << std::endl;
    std::cout << "Maintenance: " << library->getMaintenance()
              << ", Resource Consumption: " << library->getResourceConsumption()
              << ", Citizen Satisfaction: " << library->getCitizenSatisfactionImpact() << std::endl;

    // Step 2: Apply a MaintenanceCostReducer decorator
    MaintenanceCostReducer* costReducedLibrary = new MaintenanceCostReducer(library,10);
    std::cout << "\nAfter applying MaintenanceCostReducer:" << std::endl;
    std::cout << "Maintenance: " << costReducedLibrary->getMaintenance()
              << ", Resource Consumption: " << costReducedLibrary->getResourceConsumption()
              << ", Citizen Satisfaction: " << costReducedLibrary->getCitizenSatisfactionImpact() << std::endl;

    // Step 3: Apply a ResourceEfficiencyEnhancer decorator
    ResourceEfficiencyEnhancer* efficientLibrary = new ResourceEfficiencyEnhancer(costReducedLibrary,20);
    std::cout << "\nAfter applying ResourceEfficiencyEnhancer:" << std::endl;
    std::cout << "Maintenance: " << efficientLibrary->getMaintenance()
              << ", Resource Consumption: " << efficientLibrary->getResourceConsumption()
              << ", Citizen Satisfaction: " << efficientLibrary->getCitizenSatisfactionImpact() << std::endl;

    // Step 4: Apply a SatisfactionEnhancer decorator
    SatisfactionEnhancer* enhancedLibrary = new SatisfactionEnhancer(efficientLibrary,20);
    std::cout << "\nAfter applying SatisfactionEnhancer:" << std::endl;
    std::cout << "Maintenance: " << enhancedLibrary->getMaintenance()
              << ", Resource Consumption: " << enhancedLibrary->getResourceConsumption()
              << ", Citizen Satisfaction: " << enhancedLibrary->getCitizenSatisfactionImpact() << std::endl;

    // Clean up allocated memory
    delete enhancedLibrary;
}

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
    << "Maintenance cost: " << Road->getMaintenance() << endl 
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

void travelBetweenStructures(const std::string& fromName, const std::string& toName,std::tuple<CStructIterator*, Road**, CStructIterator*>& cityTuple,Transportation** cityTrans) {
    CStructIterator* fromIter = std::get<0>(cityTuple);
    CStructIterator* toIter = std::get<2>(cityTuple);

    int fromIndex = 0;
    int toIndex = 0;
    bool fromFound = false;
    bool toFound = false;

    std::cout << "Traveling from " << fromName << " to " << toName << ": " << std::endl;

    // Find the from structure
    for (fromIter->first(); !fromIter->isDone(); fromIter->next()) {
        Structure* fromStructure = fromIter->currentItem();
        if (fromStructure && fromStructure->getName() == fromName) {
            fromFound = true;
            toIndex = 0;

            // Find the to structure
            for (toIter->first(); !toIter->isDone(); toIter->next()) {
                Structure* toStructure = toIter->currentItem();
                if (toStructure && toStructure->getName() == toName) {
                    toFound = true;
                    int dist = fromIndex - toIndex;

                    // Execute travel logic based on distance
                    if (dist < 0) {
                        for (int i = toIndex; i > fromIndex; i--) {
                            cityTrans[i]->travel();
                        }
                    } else if (dist == 0) {
                        std::cout << "We are walking within the same location." << std::endl;
                    } else {
                        for (int i = toIndex; i < fromIndex; i++) {
                            cityTrans[i]->travel();
                        }
                    }
                    break; // Stop searching for 'to' structure
                }
                toIndex++;
            }
            if (!toFound) {
                std::cout << "Destination structure '" << toName << "' not found." << std::endl;
            }
            break; // Stop searching for 'from' structure
        }
        fromIndex++;
    }

    if (!fromFound) {
        std::cout << "Starting structure '" << fromName << "' not found." << std::endl;
    }
}

int main(){
    //testingTransportationSystem();
    // testStructure();
    // Decoratortest();

    // Creating basic structures
    BasicStructure* school = new BasicStructure("School", 100, 50, 80);
    BasicStructure* hospital = new BasicStructure("Hospital", 200, 150, 95);
    BasicStructure* park = new BasicStructure("Park", 30, 10, 120);

    //structuregroup
    StructureGroup* cityStructures = new StructureGroup("City Structures");
    cityStructures->add(school);
    cityStructures->add(hospital);
    cityStructures->add(park);

    Road** CityStructRoads = new Road*[3];
    CityStructRoads[0] = new Road("248 Lunnin Road", 1, 11, 111);
    CityStructRoads[1] = new Road("249 Lunnin Road", 2, 22, 222);
    CityStructRoads[2] = new Road("250 Lunnin Road", 3, 33, 333);
    RoadState* UC = new UnderConstruction();
    RoadState* work = new Working();

    
    PublicVehicle* bus = new Bus();
    Transport* publicT = new PublicTransport(bus);

    Transportation** cityTrans = new Transportation*[3];
    for(int i = 0; i < 3; i++){
        cityTrans[i] = new ConcreteObserver(CityStructRoads[i], publicT);
    }

    RoadSubject** cityRS = new RoadSubject*[3];
    Structure** cityRStruct = new Structure*[3];
    for(int i = 0; i < 3; i++){
        cityRS[i] = (CityStructRoads[i]);
        cityRS[i]->attach(cityTrans[i]);
        CityStructRoads[i]->setState(work);
        cityRS[i]->notify();
    }

    CStructIterator* cityIterator = dynamic_cast<CStructIterator*>(cityStructures->createIterator());
    std::tuple <CStructIterator*, Road**, CStructIterator*> cityTuple(cityIterator, CityStructRoads, cityIterator);

    travelBetweenStructures("School", "Park", cityTuple, cityTrans);
    
    return 0;
}

