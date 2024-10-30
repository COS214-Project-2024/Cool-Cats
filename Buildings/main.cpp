#include <iostream>
#include <vector>
using namespace std;

#include "Structure.h"
#include "StructureGroup.h"
#include "StructureDecorator.h"
#include "CStructIterator.h"
#include "SatisfactionEnhancer.h"
#include "MaintenanceCostReducer.h"
#include "ResourceEfficiencyEnhancer.h"
#include "BasicStructure.h"
#include "StructureIterator.h"

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

int main(){
    cout << "Testing << endl";
    //testStructure();
    Decoratortest();

    return 0;
}
