#include <iostream>   // Include input-output stream library
#include <string>
#include <vector>
#include <limits>
#include <regex>
#include <array>
#include <map>

#include "Structure.h"
#include "StructureGroup.h"
#include "StructureDecorator.h"
#include "CStructIterator.h"
#include "SatisfactionEnhancer.h"
#include "MaintenanceCostReducer.h"
#include "ResourceEfficiencyEnhancer.h"
#include "BasicStructure.h"
#include "StructureIterator.h"

//citizen includes:
#include "AllCitizenIterator.h"
#include "Citizen.h"
#include "CitizenIterator.h"
#include "Creator.h"
#include "HighCitizen.h"
#include "HighCitizenCreator.h"
#include "Income.h"
#include "LowCitizen.h"
#include "LowCitizenCreator.h"
#include "Mayor.h"
#include "MayorCreator.h"
#include "MayorIterator.h"
#include "MiddleCitizen.h"
#include "MiddleCitizenCreator.h"

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

// Government includes
#include "Government.h"
#include "GovernmentInvoker.h"
#include "TaxationCommand.h"
#include "PolicyImplementationCommand.h"
#include "Materials.h"
#include "Energy.h"
#include "Water.h"
#include "CityResourceMediator.h"
#include "Taxes.h"
#include "TaxMemento.h"
#include "BudgetAllocationCommand.h"

using namespace std;

//main menu
void mainMenu();

//gerneral funcitons:
void chooseFromMenu();


//for buildings:
void editStructureGroup();
void addStructureGroup();
void removeStructureGroup();

void editStructure();
void addStructure();
void removeStructure();

void addCititoBuild(int number);
void decorateStructure();


//for transport
vector<PublicTransport*> PT; // To hold all the Public transport
vector<TrainTransport*> TT; // To hold all the Train transport
vector<AirportTransport*> AT; // To hold all the Air transport
map<string, pair<vector<Road*>, vector<RoadSubject*>>> cityRoads; // To assign a road and roadSubject to a specific city group name
map<string, vector<Transportation*>> transLines; // To hold all the transport routes
map<string, Transportation*> transC2CLines; // To hold all the city to city transport routes

void editTransport();

void editTransportGroups();
void addTransportGroups();
void removeTransportGroups();
void editTransportInGroups();
void addTransportInGroups();
void removeTransportInGroups();
void createPublicType(int type, string name);
void createTrainType(int type, string name);
void createAirportType(int type, string name);
void createRoad(const std::string& roadName, const std::string& structureGroupName);
int structureIndex(StructureGroup* group, Structure* name);
void createInCityTransportRoute(int TransType, const std::string& CityName, BasicStructure* starting, BasicStructure* ending, const std::string& transName, const std::string& routeName);
void createC2CTransportRoute(int transType, StructureGroup* starting, StructureGroup* ending, const std::string& transName, const std::string& routeName);
void RegularInCityTravel(int TransType, const std::string& CityName, BasicStructure* starting, BasicStructure* ending, const std::string& transName);
void travelRoute(string routeName);
void travelC2CRoute(string routeName);
void createTransportation(int num);
int error(int min, int max);
string stringError();
void travelInCity();
void newTransportMenu();
void newRouteMenu();
void createInRoute();
void createC2CRoute();
void travelMenu();
void deleteTransportMenu();
void deleteTRoute();


//for citizens
void addCitizens();
void addMayor();
void addCitizenToBuildings();
void currentCitizenPopulation();
int getCitizenPopulation();
void makeCitizensVote();
void currentMayor();
void currentSatisfaction();
bool foundCity(string cityChoice);
int getCityIndex(string cityChoice);

//Global variables for Citizen
bool citizenIntro = false;
bool votedOnce = false;
int previousPopulation = 0;
double previousSatisfaction = 0;
LowCitizen * SENTINEL = new LowCitizen();
Mayor * SENTINEL_MAYOR = new Mayor();
regex escape_characters(R"(\\[nt\\\"'])");

// Global variables for Government
Government* government;
GovernmentInvoker* invoker;
Materials* materials;
CityResourceMediator* resourceMediator;
Energy* energy;
Water* water;

void errorMessage();
CStructIterator* createIteratorForGroup(StructureGroup* s );
void exit();
void viewCity();

StructureGroup* createCityHall();

void createGovernment();



void editTransport();
void printLines();


vector<StructureGroup*> arr; // this keeps track of all the stucture groups that have been created
vector<CStructIterator*> iteratorArr ; // this keeps track of iterators that have been created ie each structure is in a structure group and we can iterate over each structure in each structure group through this.
int main(){
    cout << "WELCOME TO THE COOL CATS CITY SIMULATOR" << endl;

    cout << "-------------------------------------------" << endl;

    cout << "We will need to start by creating the city hall, this a default standard and the government will be created as well. If you want to make changes to government options will appear as you build the city :)" << endl;

    cout << "Press 1 to create City hall and government" << endl;

    //NB City hall and Government are created by default.s

    //utilites for this should be added
        error(1,2);
        arr.push_back(createCityHall());
        iteratorArr.push_back(createIteratorForGroup(arr.front())); // potential erros can arise from here
        createGovernment();
        createRoad("CityRoad","CityHallGroup");
    
    printLines();
    cout << "Great you have created the city hall and government. From here on out there will be an option to view details of your city :)" << endl;
    
    //this will be our main screen

    //When a user click one of these numbers, then they should be able to stuff based on the number added
    //we will need to do some error handling here
    //we use a while loop so whenever we break from one of the cases so that this menu will get shown after
    //You can printlines if you would like to seperate for clarity
    //You can exit to end program

  
    mainMenu();
    
    

    //pseudo code
    // StructureGroup* grouptest = new StructureGroup("Test Group");
    // arr.push_back(grouptest);
    // BasicStructure* testStructure = new BasicStructure("test1",'R',100);
    // BasicStructure* testStructure2 = new BasicStructure("test2",'R',100);
    // BasicStructure* testStructure3 = new BasicStructure("test3",'R',100);
    // grouptest->add(testStructure);
    // grouptest->add(testStructure2);
    // grouptest->add(testStructure3);

    // HighCitizenCreator high;
    // Citizen *citizen = high.specificCitizenOperation("unemployed",65 ,nullptr);
    // addCititoBuild(citizen);
    

    return 0;
}

//general funcitons

void mainMenu() {
    int option = 0;
    bool condition = true;
    while (option != 4 && condition)  {  // Keep showing the menu until "Exit" is chosen
        printLines();
        cout << "Main Menu" << endl;
        cout << "1 : Edit Structure Groups" << endl;
        cout << "2 : Edit Structures" << endl;
        cout << "3 : View City" << endl;
        cout << "4 : Exit" << endl;
        cout << "5 : Edit Transport" << endl;
        cout << "6 : Edit Government" << endl;
        cout << "7 : Add Utilities" << endl;
        cout << "8 : Add Citizens" << endl;
        cout << "Select NUMBER: ";

        //validate user input
        while (!(cin >> option) || option < 1 || option > 8) {
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            cin.clear();  // Clear the error 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // invalid input
            cout << "Select NUMBER: ";
        }

        // Process the user's choice
        switch (option) {
            case 1:
                editStructureGroup();
                break;

            case 2:
                editStructure();
                break;

            case 3:
                viewCity();
                mainMenu();
                break;

            case 4:
                cout << "Exiting..." << endl;
                exit();
                condition = false;
                break;

            case 5:
                editTransport();
                break;

            case 6:
                // Call editGovernment function
                break;

            case 7:
                // Call addUtilities function
                break;

            case 8:
                addCitizens();
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
        //cout << "we have broken out of the final" << endl;
        condition = false;
        // printLines();
    }
}


void printLines(){
    cout << "---------------------------------------------------------------" << endl;
}

void errorMessage(){

}

void exit(){
    viewCity();
    // exit(1);
    // cout << "We got here" << endl;

}

void viewCity() { 
    printLines();

    // ANSI color code for bold blue (change as needed)
    const string groupColor = "\033[1;34m";
    const string resetColor = "\033[0m";

    for (StructureGroup* group : arr) {
        if (!group) continue; // Skip any null groups

        // Print the structure group name in bold bluen
        cout << groupColor << group->getName() << resetColor << endl;

        // Create an iterator to go through each structure in the group
        CStructIterator* iterator = group->createIterator();

        // Traverse each structure within the group
        for (iterator->first(); !iterator->isDone(); iterator->next()) {
            Structure* currentStructure = iterator->currentItem();
            BasicStructure* basicStructure = dynamic_cast<BasicStructure*>(currentStructure);

            if (basicStructure) {
                // Print each structure's name and type
                cout << "- " << basicStructure->getName() 
                     << " (" << basicStructure->getType() << ")" << endl;
                cout << "\t Utilites" << endl;
                cout << "\t PowerLeft: " << basicStructure->getKilowatts() << endl;
                cout << "\t WaterLeft: " << basicStructure->getAvailableWater() << endl;
                cout << "\t Sewage Amount: " << basicStructure->getSewageAmount() << endl;
                cout << "\t Waste Amount: " << basicStructure->getWasteAmount() << endl;
            }
        }

        delete iterator; // Clean up iterator
        printLines();
    }

    printLines();
}

CStructIterator* createIteratorForGroup(StructureGroup* s ){
    CStructIterator *newIterator = s->createIterator();
    return newIterator;
}

StructureGroup* createCityHall(){
    //this is default created, so its done in the before the main menu
    StructureGroup * cityhallGroup = new StructureGroup("CityHallGroup");
    BasicStructure* cityHall = new BasicStructure("CityHall", 'L',100);
    string n = "PWSB"; 
    cityHall->addUtilities(n, cityHall);
    cityhallGroup->add(cityHall);

    return cityhallGroup;
}

void createGovernment() {
    resourceMediator = new CityResourceMediator();
    government = new Government(resourceMediator);
    invoker = new GovernmentInvoker();
    materials = new Materials();
    energy = new Energy();
    water = new Water();
}

void displayMenu() {
    cout << "\nCity Builder Simulation Menu:\n";
    cout << "1. Set Tax Rate\n";
    cout << "2. Implement Policy\n";
    cout << "3. Allocate Government Budget\n";
    cout << "4. Coordinate Resources for a Project\n";
    cout << "5. Collect Taxes\n";
    cout << "6. Restore Taxes to previous\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void editGovernment() {
    int choice;
    while (true) {
        displayMenu();
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid choice. Please select an option from the menu: ";
        }
        switch (choice) {
            case 1: {  // Set Tax Rate
                float taxRate;
                cout << "Enter new tax rate (e.g., 0.15 for 15%): ";
                while (!(cin >> taxRate) || taxRate < 0 || taxRate > 1) {
                    cin.clear(); // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                    cout << "Invalid tax rate. Please enter a value between 0 and 1: ";
                }
                government->setTaxRate(taxRate); // Update tax rate
                TaxMemento* one = government->getTax()->createMemento();
                government->storeMemento(one);
                break;
            }
            case 2: {  // Implement Policy
                string policy;
                cout << "Enter policy name (e.g., Green Energy Initiative): ";
                cin.ignore();  
                getline(cin, policy);
                if (policy.empty()) {
                    cout << "Policy name cannot be empty.\n";
                    break;
                }
                auto policyCommand = make_unique<PolicyImplementationCommand>(nullptr, policy, government);
                invoker->setCommand(move(policyCommand));
                invoker->executeCommand();
                break;
            }
            case 3: {  // Allocate Government Budget
                double amount;
                cout << "Enter amount to allocate from budget: ";
                while (!(cin >> amount) || amount < 0) {
                    cin.clear(); // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                    cout << "Invalid amount. Please enter a positive value: ";
                }
                auto budgetCommand = make_unique<BudgetAllocationCommand>(nullptr, amount, government);
                invoker->setCommand(move(budgetCommand));
                invoker->executeCommand();
                break;
            }
            case 4: {  // Coordinate Resources for a Project
                string projectType;
                int materialsAmount, energyAmount, waterAmount;
                cout << "Enter project name (e.g., Residential Expansion): ";
                cin.ignore();
                getline(cin, projectType);
                if (projectType.empty()) {
                    cout << "Project name cannot be empty.\n";
                    break;
                }
                cout << "Enter amount of materials required: ";
                while (!(cin >> materialsAmount) || materialsAmount < 0) {
                    cin.clear(); // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                    cout << "Invalid amount. Please enter a positive value: ";
                }
                cout << "Enter amount of energy required: ";
                while (!(cin >> energyAmount) || energyAmount < 0) {
                    cin.clear(); // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                    cout << "Invalid amount. Please enter a positive value: ";
                }
                cout << "Enter amount of water required: ";
                while (!(cin >> waterAmount) || waterAmount < 0) {
                    cin.clear(); // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                    cout << "Invalid amount. Please enter a positive value: ";
                }
                resourceMediator->coordinateResources(projectType, materialsAmount, energyAmount, waterAmount);
                break;
            }
            case 5: {
                AllCitizenIterator* iterate = SENTINEL->createCitizenIterator();
                government->collection(iterate);
                cout << "Taxes have been collected\n";
                delete iterate;
                break;
            }
            case 6: {
                cout << "This is the current tax rate " << government->getTax()->getTaxRate() << endl;
                government->setTaxRate(government->getMemento()->getState()->getTaxRate());
                cout << "Taxes have been restored to " << government->getTax()->getTaxRate() << endl;
                break;
            }
            case 7:
                cout << "Exiting the government menu.\n";
                return;
            default:
                cout << "Invalid choice. Please select an option from the menu.\n";
        }
    }
}

void chooseFromMenu(){
    cout << "Choose from the menu" << endl;
}



//building funcitons

//function to add citizen to building:
void addCititoBuild(int number) {
    if (number < 0) {
        throw std::invalid_argument("amount of citizens cannot be negative");
    }

    bool structureFound = false;

    // Display all available structures in each StructureGroup
    for (auto* group : arr) {
        if (!group) continue; // null groups

        cout << "-------------------------------" << endl;
        cout << "Structures available in Area (" << group->getName() << "):" << endl;

        // Create an iterator for the current StructureGroup
        CStructIterator* iterator = group->createIterator();

        // Traverse through each structure 
        for (iterator->first(); !iterator->isDone(); iterator->next()) {
            Structure* currentStructure = iterator->currentItem();
            BasicStructure* basicStructure = dynamic_cast<BasicStructure*>(currentStructure);

            if (basicStructure) {
                // Print the structure's name and type (e.g., Commercial, Residential)
                cout << "- " << basicStructure->getName() << " (" << basicStructure->getType() << ")" << endl;
                structureFound = true;
            }
        }

        delete iterator; // Clean up iterator after use
    }

    if (!structureFound) {
        cout << "No available structures found in any StructureGroup." << endl;
        return;
    }

    // Prompt the user to enter the name of the building to add the citizen
    cout << "Enter the name of the structure/building to add the citizen to: ";
    string buildingName;
    cin.ignore();
    getline(cin, buildingName);

    // Search for the specified building by name
    for (auto* group : arr) {
        if (!group) continue; // null groups

        // Create an iterator for the current StructureGroup
        CStructIterator* iterator = group->createIterator();

        // Traverse each structure within the group
        for (iterator->first(); !iterator->isDone(); iterator->next()) {
            Structure* currentStructure = iterator->currentItem();
            BasicStructure* basicStructure = dynamic_cast<BasicStructure*>(currentStructure);

            if (basicStructure && basicStructure->getName() == buildingName) {
                // Add the citizen to the found building
                try {
                    basicStructure->addcitizen(number);
                    cout << "Citizens added successfully to " << buildingName << "." << endl;
                } catch (const std::exception& e) {
                    cout << "Error adding citizens: " << e.what() << endl;
                }

                delete iterator; // Clean up iterator before returning
                return;
            }
        }

        delete iterator; // Clean up iterator after checking each group
    }

    // If no structure with the specified name is found
    cout << "Structure with the name '" << buildingName << "' not found." << endl;
}


void editStructureGroup(){

    printLines();
    //this will allow us to add and remove structure groups from the array

    int option = 0;
    
    while(true) {
        printLines();
        cout << "Edit Structure Group Menu" << endl;
        cout << "1: Add" << endl;
        cout << "2: Remove" << endl;
        cout << "3: View City" << endl;
        cout << "4: Return to Main Menu" << endl;
        cout << "Please enter an option (1-4): ";

        cin >> option;

        if(cin.fail() || option < 1 || option > 4){
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else {
            break; //input valid
        }
    }
    
    printLines();

    switch(option) {
        case 1:
            cout << "Adding structure group:" << endl;
            addStructureGroup();
            break;
        
        case 2:
            cout<< "Remove structure group" << endl;
            removeStructureGroup();
            break;

        case 3: 
            viewCity();
            editStructureGroup();
            break;
            
        case 4:
            mainMenu();
            break;

    }

    

    //handle cases here
    //also note you will need to create a new iterator for this .There is an vector for iterator which we will use a 1:1 location for the iterator and groups array. SO position 1 of the iterator will correspond to group in postion 1 of the structure group.


    // printLines();

}

void addStructureGroup(){
    //this will add a structure group to the vector arr
    //you can edit here as you see fit. once you are done you shouldnt need to anything as it will go back to main screen automatically howver you could call view city and print lines to show that the new thing has been indeed added to the array
    string name;
    cout << "Enter Name of area you would like to add" << endl;
    cin >> name;

    StructureGroup* newStructureGroup = new StructureGroup(name);
    arr.push_back(newStructureGroup);

    printLines();
    
    cout << "YOU have created a new area: " << name << endl;
    editStructureGroup();
}

void removeStructureGroup(){
    //this will remove a structure group to the vector arr
    //make sure after something is removed, the vector postion doesnt become empty and everything ahead is brought back.
    if( arr.empty()){
        cout << "No structure groups available to remove." << endl;
        return;
    }

    string name;
    cout << "Enter the name of the Structuregroup to remove: ";
    cin.ignore();
    getline(cin, name);

    auto it = find_if(arr.begin(), arr.end(), [&name](StructureGroup* group){
        return group->getName() == name;
    });

    if( it != arr.end() ){
        delete *it;
        arr.erase(it);

        cout << "Structture group \"" << name << "\" removed successfully." << endl;
    }else {
        cout << "No structure group found with the name \"" << name << "\"." << endl;
    }

    editStructureGroup();
}

void editStructure(){

    int option = 0;
   
    while(true) {
        printLines();
        cout << "Edit structure Menu" << endl;
        cout << "1: Add" << endl;
        cout << "2: Remove" << endl;
        cout << "3: View city" << endl;
        cout << "4: Return to Main Menu" << endl;
        cout << "5: Update structures" << endl;
        cout << "Please enter an option (1-5): ";

        cin >> option;

        if(cin.fail() || option < 1 || option > 5){
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear(); // Clear error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input 
        }else {
            break; //input valid
        }
    }

    printLines();

    switch (option) {
        case 1:
            cout << "ADD structure..." << endl;
            addStructure();
            break;

        case 2:
            cout << "Remove structure..." << endl;
            removeStructure();
            break;
        
        case 3:
          viewCity();
          editStructure();
            break;
            
        case 4:
            mainMenu(); 
            break;

        case 5:
            decorateStructure();
            editStructure();

            break;

        default:
            break;
    }
     

}

void addStructure(){
    if ( arr.empty()){
        cout << "No structure groups avialable. Please create a structure group first." << endl;
        return;
    }

    cout << "Select a Structure Group to add the new structure to:" << endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << i << ": " << arr[i]->getName() << endl;
    }

    size_t groupIndex;
    cout << "Enter the index of the Structure group: ";
    while ( !(cin >> groupIndex) || groupIndex < 0 || groupIndex >= arr.size()) {
        cout << "Invalid input. Please enter a valid group index. " << endl;
        cin.clear();
    }

    string structureName;
    cout << "Enter the name of the new structure: ";
    cin.ignore();
    getline(cin, structureName);

    char structuretype;
    cout << "Choose from the Menu: " << endl;
    cout << "R: Residential" << endl;
    cout << "C: Commercial" << endl;
    cout << "I: Industrial" << endl;
    cout << "L: Landmarks" << endl;

    while(true) {
        cout << "Enter the structure type ( R, C, I, L) :";
        cin >> structuretype;
        if (structuretype == 'R' || structuretype == 'C' || structuretype == 'I' || structuretype == 'L'){
            break;
        }else {
            cout << "Invalid input. Please enter R, C, I, or L." << endl;
        }
    }

    int maxCap;

    switch (structuretype) {
        case 'R':
            cout << "Enter the maximum capacity for Residential structure (up to 300): ";
            while (!(cin >> maxCap) || maxCap < 1 || maxCap > 300){
                cout << "Invalid capacity. Please enter a value between 1 and 300." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;

        case 'C':
            cout << "Enter the maximum capacity for Commercial structure (up to 1000): ";
            while (!(cin >> maxCap) || maxCap < 1 || maxCap > 1000) {
                cout << "Invalid capacity. Please enter a value between 1 and 1000." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;

        case 'I':
            cout << "Enter the maximum capacity for Industrial structure (up to 1000): ";
            while (!(cin >> maxCap) || maxCap < 1 || maxCap > 1000) {
                cout << "Invalid capacity. Please enter a value between 1 and 1000." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        
        case 'L':
            cout << "Enter the maximum capacity for Landmark structure (up to 700): ";
            while (!(cin >> maxCap) || maxCap < 1 || maxCap > 700) {
                cout << "Invalid capacity. Please enter a value between 1 and 700." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
    }

    BasicStructure* newStructure = new BasicStructure(structureName, structuretype, maxCap);
    string n = "PWSB"; 
    newStructure->addUtilities(n, newStructure);
    arr[groupIndex]->add(newStructure);

    CStructIterator* newIterator = arr[groupIndex]->createIterator();
    int numStuctInGroup = 0;
    cout << "Structure added. Available structures in area \"" << arr[groupIndex]->getName() << "\":" << endl;
    for (newIterator->first(); !newIterator->isDone(); newIterator->next()){
        numStuctInGroup++;
        Structure* structure = newIterator->currentItem();
        if (structure){
            cout << "- " << structure->getName() << endl;
        }
    }

    auto& roads = cityRoads[arr[groupIndex]->getName()].first;
    int num = numStuctInGroup%4;
    std::cout << "The number of structures: "<< num << std::endl;
    std::cout << "The number of roads: " << roads.size() << std::endl;
    if(num == 0){
        std::string roadName;
        std::cout << "New road needed." << std::endl;
        std::cout << "Enter name of new road:" << std::endl;

        // Validate that the road name is not empty and only contains valid characters
        std::regex validNamePattern("^[A-Za-z0-9\\s]+$"); // Allows letters, numbers, and spaces

        while (true) {
            std::getline(std::cin, roadName);

            // Check if road name matches the pattern and is not empty
            if (!roadName.empty() && std::regex_match(roadName, validNamePattern)) {
                break; // Valid road name; exit loop
            }

            std::cout << "Invalid road name. Please enter a valid name (letters, numbers, and spaces only):" << std::endl;
            std::cin.clear();
        }

        // Call createRoad with the validated road name
        createRoad(roadName, "CityGroupName"); // Replace with actual group name if needed
        
    }

    delete newIterator;

    editStructure();


}

void removeStructure(){
    if (arr.empty()) {
        cout << "No structure groups available. Please create a structure group first." << endl;
        return;
    }

    cout << "Select a StructureGroup to remove a structure from:" << endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << i << ": " << arr[i]->getName() << endl;
    }

    size_t groupIndex;
    cout << "Enter the index of the StructureGroup: ";
    while (!(cin >> groupIndex) || groupIndex < 0 || groupIndex >= arr.size()) {
        cout << "Invalid input. Please enter a valid index." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    CStructIterator* iterator = arr[groupIndex]->createIterator();

    cout << "Structures available in \"" << arr[groupIndex]->getName() << "\":" << endl;
    vector<Structure*> structures; // To store structure pointers for easy lookup
    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        Structure* structure = iterator->currentItem();
        if (structure) {
            cout << "- " << structure->getName() << endl;
            structures.push_back(structure);
        }
    }
    delete iterator;

    if (structures.empty()) {
        cout << "No structures available to remove in this group." << endl;
        return;
    }

    string structureName;
    cout << "Enter the name of the structure to remove: ";
    cin.ignore();
    getline(cin, structureName);

    bool found = false;
    for (Structure* structure : structures) {
        if (structure->getName() == structureName) {
            arr[groupIndex]->remove(structure);
            delete structure; 
            cout << "Structure \"" << structureName << "\" removed successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Structure with name \"" << structureName << "\" not found in the group." << endl;
    }

    editStructure();


}

void decorateStructure(){
    cout << "Select a structure to decorate:" << endl;

    bool structureFound = false;

    //avialable structures
    for (auto* group : arr){
        if (!group) continue;

        CStructIterator* iterator = group->createIterator();

        for (iterator->first(); !iterator->isDone(); iterator->next()) {
            Structure* currentStructure = iterator->currentItem();
            BasicStructure* basicStructure = dynamic_cast<BasicStructure*>(currentStructure);

            if (basicStructure) {
                cout << "- " << basicStructure->getName() << " (" << basicStructure->getType() << ")" << endl;
                structureFound = true;
            }
        }

        delete iterator;
    }

    if(!structureFound){
        cout << "No structures available for decoration." << endl;
        return;
    }

    //get structure from user:
    cout << "Enter the name of the structure to decorate: ";
    string buildingName;
    cin.ignore(); // Clear input buffer
    getline(cin, buildingName);

    Structure* selectedStructure = nullptr;

    for (auto* group : arr){
        if (!group) continue;

        CStructIterator* iterator = group->createIterator();

        for (iterator->first(); !iterator->isDone(); iterator->next()){
            Structure* currentStructure = iterator->currentItem();
            BasicStructure* basicStructure = dynamic_cast<BasicStructure*>(currentStructure);

            if (basicStructure && basicStructure->getName() == buildingName) {
                selectedStructure = basicStructure;
                break;
            }
        }

        delete iterator;
        if(selectedStructure) break; // structure found
    }

    if(!selectedStructure){
         cout << "Select decoration type:" << endl;
        cout << "1: Satisfaction Enhancer" << endl;
        cout << "2: Resource Efficiency Enhancer" << endl;
        cout << "3: Maintenance Cost Reducer" << endl;
        int decorationOption;
        cin >> decorationOption;

        switch (decorationOption) {
            case 1:
                float boost;
                cout << "Enter satisfaction boost value: ";
                cin >> boost;

                if(cin.fail() || boost < 0.0f || boost >100){
                    cout << "Invalid boost value. It must be a non-negative number nad less than 100." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else {
                    selectedStructure = new SatisfactionEnhancer(selectedStructure, boost);
                    cout << "Satisfaction enhancer applied with a boost of " << boost << "!" << endl;
                }
                
                break;

            case 2:
                float effboost;
                cout << "Enter Resource efficiency boost: ";
                cin >> effboost;

                if(cin.fail() || effboost < 0.0f || effboost >100){
                    cout << "Invalid boost value. It must be a non-negative number nad less than 100." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else{
                    selectedStructure = new ResourceEfficiencyEnhancer(selectedStructure, effboost);
                    cout << "Resource efficiency enhancer applied with a boost of " << effboost << "!" << endl;
                }

                break;

            case 3:
                float reduction;
                cout << "Enter Maintencance cost reduction perscentage: ";
                cin >> reduction;

                if(cin.fail() || reduction < 0.0f || reduction > 100){
                    cout << "Invalid reduction percentage. It must be a non-negative number nad less than 100." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else {
                    selectedStructure = new MaintenanceCostReducer(selectedStructure,reduction);
                    cout << "Maintenance enhancer applied with a reduction of " << reduction << "!" << endl;
                }
                break;
            default:
                cout << "Invalid decoration option." << endl;
                return;
        }
    }
}



//Transport functions
void editTransport(){
    //return
    //add transport route from one place to another and mode
    printLines();
    chooseFromMenu();
    cout << "Transport Menu" << endl;
    cout << "1: Create new Transport" << endl;
    cout << "2: Create new Transport Route" << endl;
    cout << "3: Delete Transport" << endl;
    cout << "4: Delete Transport Route" << endl;
    cout << "5: Exit" << endl;
    int choice = error(1,7);
    switch(choice){
        case 1:
            newTransportMenu();
            break;
        case 2:
            newRouteMenu();
            break;
        case 3:
            deleteTransportMenu();
            break;
        case 4:
            deleteTRoute();
            break;
        case 5:
            mainMenu();
            break;
    }

}

void deleteTRoute(){
    printLines();
    chooseFromMenu();
    std::cout << "Select route to delete" << std::endl;
    cout << "1: In City Route" << endl;
    cout << "2: City to City Route" << endl;
    cout << "3: Exit" << endl;
    int choice = error(1,3);
    switch(choice){
        case 1:{
            printLines();
            string toBeDeleted = "";
            std::cout << "In city Routes: " << std::endl;
            printLines();
            for (const auto& entry : transLines) {
                std::cout << entry.first << std::endl;  // Print the key of transLines
            }
            printLines();
            std::cout << "Please select what Route to delete" << std::endl;
            string word = stringError();
            for (const auto& entry : transLines) {
                if(entry.first == word){
                    toBeDeleted = word;
                    break;
                }
            }
            printLines();
            if(toBeDeleted != ""){
                printLines();
                std::cout << "Are you sure you want to delete " << toBeDeleted  << "(1-Yes/2-Cancel)?" << std::endl;
                std::cout << "This cannot be undone" << std::endl;
                int confirm = error(1,2);
                switch(confirm){
                    case 1:{
                        for (auto* transport : transLines[toBeDeleted]) {
                            delete transport;
                        }
                        transLines[toBeDeleted].clear(); 
                        transLines.erase(toBeDeleted);
                        std::cout << "Deletion Successful" << std::endl;
                        deleteTRoute();
                    }
                    break;
                    case 2:{
                        std::cout << "Cancelled Deletion" << std::endl;
                        deleteTRoute();
                    }
                    break;
                }
            }
            else{
                std::cout << "Route Doesn't Exist" << std::endl;
                deleteTRoute();
            }
        }
        break;
        case 2:{
            printLines();
            string toBeDeleted = "";
            std::cout << "City to City Routes: " << std::endl;
            printLines();
            for (const auto& entry : transC2CLines) {
                std::cout << entry.first << std::endl;  // Print the key of transLines
            }
            printLines();
            std::cout << "Please select what Route to delete" << std::endl;
            string word = stringError();
            for (const auto& entry : transC2CLines) {
                if(entry.first == word){
                    toBeDeleted = word;
                    break;
                }
            }
            printLines();
            if(toBeDeleted != ""){
                printLines();
                std::cout << "Are you sure you want to delete " << toBeDeleted  << "(1-Yes/2-Cancel)?" << std::endl;
                std::cout << "This cannot be undone" << std::endl;
                int confirm = error(1,2);
                switch(confirm){
                    case 1:{
                        delete transC2CLines[toBeDeleted];
                        // Erase the entry from the map
                        transC2CLines.erase(toBeDeleted);

                        std::cout << "Deletion Successful" << std::endl;
                        deleteTRoute();  // Assuming you want to repeat the route deletion process
                    }
                    break;
                    case 2:{
                        std::cout << "Cancelled Deletion" << std::endl;
                        deleteTRoute();
                    }
                    break;
                }
            }
            else{
                std::cout << "Route Doesn't Exist" << std::endl;
                deleteTRoute();
            }
        }
        break;
        case 3:{
            editTransport();
        }
    }
}

void deleteTransportMenu(){
    printLines();
    chooseFromMenu();
    cout << "Delete Transport Menu" << endl;
    cout << "1: Delete Public Transport" << endl;
    cout << "2: Delete Train Transport" << endl;
    cout << "3: Delete Air Transport" << endl;
    cout << "4: Exit" << endl;
    int choice = error(1,4);
    switch(choice){
        case 1:{
            std::cout << "Viewing Current Public Transports" << std::endl;
            printLines();
            std::cout << "Public Transports:" << std::endl;
            for(size_t i = 0; i < PT.size(); i++){
                std::cout << i << ": " << PT[i]->getVehicle()->getName() << std::endl;
            }
            std::cout << "Please select which Transport to delete:" << std::endl;
            string del = stringError();
            PublicTransport* toBeDeleted = NULL;
            int index = 0;
            for(size_t i = 0; i < PT.size(); i++){
                if(PT[i]->getVehicle()->getName() == del){
                    toBeDeleted = PT[i];
                    index = i;
                    break;
                }
            }
            if(toBeDeleted != NULL){
                printLines();
                std::cout << "Are you sure you want to delete (1-Yes/2-Cancel)?" << toBeDeleted->getVehicle()->getName() << std::endl;
                std::cout << "This cannot be undone" << std::endl;
                std::cout << "This also negates any travel routes associated to this mode of transport" << std::endl;
                int confirm = error(1,2);
                switch(confirm){
                    case 1:{
                        delete toBeDeleted;
                        PT.erase(PT.begin() + index);
                        std::cout << "Deletion Successful" << std::endl;
                        deleteTransportMenu();
                    }
                    break;
                    case 2:{
                        std::cout << "Cancelled Deletion" << std::endl;
                        deleteTransportMenu();
                    }
                    break;
                }
            }
            else{
                std::cout << "Transport Doesn't Exist" << std::endl;
                deleteTransportMenu();
            }
        }
        break;
        case 2:{
            std::cout << "Viewing Current Train Transports" << std::endl;
            printLines();
            std::cout << "Train Transports:" << std::endl;
            for(size_t i = 0; i < TT.size(); i++){
                std::cout << i << ": " << TT[i]->getVehicle()->getName() << std::endl;
            }
            std::cout << "Please select which Transport to delete:" << std::endl;
            string del = stringError();
            TrainTransport* toBeDeleted = NULL;
            int index = 0;
            for(size_t i = 0; i < TT.size(); i++){
                if(TT[i]->getVehicle()->getName() == del){
                    toBeDeleted = TT[i];
                    index = i;
                    break;
                }
            }
            if(toBeDeleted != NULL){
                printLines();
                std::cout << "Are you sure you want to delete (1-Yes/2-Cancel)?" << toBeDeleted->getVehicle()->getName() << std::endl;
                std::cout << "This cannot be undone" << std::endl;
                std::cout << "This also negates any travel routes associated to this mode of transport" << std::endl;
                int confirm = error(1,2);
                switch(confirm){
                    case 1:{
                        delete toBeDeleted;
                        TT.erase(TT.begin() + index);
                        std::cout << "Deletion Successful" << std::endl;
                        deleteTransportMenu();
                    }
                    break;
                    case 2:{
                        std::cout << "Cancelled Deletion" << std::endl;
                        deleteTransportMenu();
                    }
                    break;
                }
            }
            else{
                std::cout << "Transport Doesn't Exist" << std::endl;
                deleteTransportMenu();
            }
        }
        break;
        case 3: {
            std::cout << "Viewing Current Airplane Transports" << std::endl;
            printLines();
            std::cout << "Airplane Transports:" << std::endl;
            for(size_t i = 0; i < AT.size(); i++){
                std::cout << i << ": " << AT[i]->getVehicle()->getName() << std::endl;
            }
            std::cout << "Please select which Transport to delete:" << std::endl;
            string del = stringError();
            AirportTransport* toBeDeleted = NULL;
            int index = 0;
            for(size_t i = 0; i < AT.size(); i++){
                if(AT[i]->getVehicle()->getName() == del){
                    toBeDeleted = AT[i];
                    index = i;
                    break;
                }
            }
            if(toBeDeleted != NULL){
                printLines();
                std::cout << "Are you sure you want to delete (1-Yes/2-Cancel)?" << toBeDeleted->getVehicle()->getName() << std::endl;
                std::cout << "This cannot be undone" << std::endl;
                std::cout << "This also negates any travel routes associated to this mode of transport" << std::endl;
                int confirm = error(1,2);
                switch(confirm){
                    case 1:{
                        delete toBeDeleted;
                        AT.erase(AT.begin() + index);
                        std::cout << "Deletion Successful" << std::endl;
                        deleteTransportMenu();
                    }
                    break;
                    case 2:{
                        std::cout << "Cancelled Deletion" << std::endl;
                        deleteTransportMenu();
                    }
                    break;
                }
            }
            else{
                std::cout << "Transport Doesn't Exist" << std::endl;
                deleteTransportMenu();
            }
        }
        break;
        case 4:
            editTransport();
            break; 
 
    }   
}

void travelMenu(){
    printLines();
    chooseFromMenu();
    cout << "Travel Menu" << endl;
    cout << "1: Travel In City" << endl;
    cout << "2: Travel Between Cities" << endl;
    cout << "3: Travel on created Route" << endl;
    cout << "4: Exit" << endl;
    int choice = error(1,4);
    switch(choice){
        case 1:{
            travelInCity();
        }
    }
}
void travelInCity(){
        std::cout << "Please select Transport Type:" << std::endl;
        std::cout << "1: Public Transport" << std::endl;
        std::cout << "2: Train Transport" << std::endl;
        int choice = error(1,2);
        switch(choice){
            case 1:{
                int transType = choice;
                string cityName = "";
                BasicStructure* startB = NULL;
                BasicStructure* endB = NULL;
                string transName = "";
                std::cout << "List of Cities: "<< std::endl;
                printLines();
                for(size_t i = 0; i < arr.size(); i++){
                    std::cout << i << ": " << arr[i]->getName() << std::endl;
                }
                printLines();
                std::cout << "Enter City Name:" << std::endl;
                string word = stringError();
                printLines();
                for(size_t i = 0; i < arr.size(); i++){
                    if(arr[i]->getName() == word){
                        cityName = word;
                        vector<Structure*> buildings = arr[i]->getChildren();
                        std::cout << "List of Structures in " << arr[i]->getName() << std::endl;
                        printLines();
                        for(size_t i = 0; i < buildings.size(); i++){
                            std::cout << i << ": " << buildings[i]->getName() << std::endl;
                        }
                        std::cout << "Enter start building: " << std::endl;
                        string start = stringError();
                        printLines();
                        for(size_t i = 0; i < buildings.size(); i++){
                            if(buildings[i]->getName() == start){
                                startB = dynamic_cast<BasicStructure*>(buildings[i]);
                                break;
                            }
                        }
                        std::cout << "Enter end building: " << std::endl;
                        string ending = stringError();
                        printLines();
                        for(size_t i = 0; i < buildings.size(); i++){
                            if(buildings[i]->getName() == ending){
                                endB = dynamic_cast<BasicStructure*>(buildings[i]);
                                break;
                            }
                        }
                        break;
                    }
                }
                std::cout << "List of all Public Transports: " << std::endl;
                printLines();
                std::cout << "Public Transports:" << std::endl;
                for(size_t i = 0; i < PT.size(); i++){
                    std::cout << i << ": " << PT[i]->getVehicle()->getName() << std::endl;
                }
                std::cout << "Enter a Transport Name: " << std::endl;
                string tName = stringError();
                printLines();
                for(size_t i = 0; i < PT.size(); i++){
                    if(PT[i]->getVehicle()->getName() == tName){
                        transName = tName;
                        break;
                    }
                }
                if(transType == 0 || cityName == "" || transName == "" ){
                    std::cout << "Invalid Input, please review your inputs and try again" << std::endl;
                    std::cout << "City Name: " << cityName << std::endl;
                    std::cout << "Transport Name: " << transName << std::endl;
                    travelInCity();
                }
                else if(startB == NULL || endB == NULL){
                    std::cout << "Invalid Input, no such start/end building exists" << std::endl;
                    travelInCity();
                }
                else{
                    printLines();
                    std::cout << "Traveling from: " << startB->getName() << "\n to: " << endB->getName() << std::endl;
                    RegularInCityTravel(transType, cityName, startB, endB, transName);
                    travelInCity();
                }
            }
            break;
            case 2:{
                int transType = choice;
                string cityName = "";
                BasicStructure* startB = NULL;
                BasicStructure* endB = NULL;
                string transName = "";
                string routeName = "";
                std::cout << "List of Cities: "<< std::endl;
                printLines();
                for(size_t i = 0; i < arr.size(); i++){
                    std::cout << i << ": " << arr[i]->getName() << std::endl;
                }
                printLines();
                std::cout << "Enter City Name:" << std::endl;
                string word = stringError();
                printLines();
                for(size_t i = 0; i < arr.size(); i++){
                    if(arr[i]->getName() == word){
                        cityName = word;
                        vector<Structure*> buildings = arr[i]->getChildren();
                        std::cout << "List of Structures in " << arr[i]->getName() << std::endl;
                        printLines();
                        for(size_t i = 0; i < buildings.size(); i++){
                            std::cout << i << ": " << buildings[i]->getName() << std::endl;
                        }
                        std::cout << "Enter start building: " << std::endl;
                        string start = stringError();
                        printLines();
                        for(size_t i = 0; i < buildings.size(); i++){
                            if(buildings[i]->getName() == start){
                                startB = dynamic_cast<BasicStructure*>(buildings[i]);
                                break;
                            }
                        }
                        std::cout << "Enter end building: " << std::endl;
                        string ending = stringError();
                        printLines();
                        for(size_t i = 0; i < buildings.size(); i++){
                            if(buildings[i]->getName() == ending){
                                endB = dynamic_cast<BasicStructure*>(buildings[i]);
                                break;
                            }
                        }
                        break;
                    }
                }
                std::cout << "List of all Train Transports: " << std::endl;
                printLines();
                std::cout << "Train Transports:" << std::endl;
                for(size_t i = 0; i < TT.size(); i++){
                    std::cout << i << ": " << TT[i]->getVehicle()->getName() << std::endl;
                }
                std::cout << "Enter a Transport Name: " << std::endl;
                string tName = stringError();
                printLines();
                for(size_t i = 0; i < TT.size(); i++){
                    if(TT[i]->getVehicle()->getName() == tName){
                        transName = tName;
                        break;
                    }
                }
                std::cout << "Enter a route name: " << std::endl;
                routeName = stringError();
                printLines();
                if(transType == 0 || cityName == "" || transName == "" || routeName == "" ){
                    std::cout << "Invalid Input, please review your inputs and try again" << std::endl;
                    std::cout << "City Name: " << cityName << std::endl;
                    std::cout << "Transport Name: " << transName << std::endl;
                    std::cout << "Route Name: " << routeName << std::endl;
                    createInRoute();
                }
                else if(startB == NULL || endB == NULL){
                    std::cout << "Invalid Input, no such start/end building exists" << std::endl;
                    createInRoute();
                }
                else{
                    printLines();
                    createInCityTransportRoute(transType, cityName, startB, endB, transName, routeName);
                    std::cout << "Route created!" << std::endl;
                    newRouteMenu();
                }
            }
            break;
        }
}
void newRouteMenu(){
    printLines();
    chooseFromMenu();
    cout << "Route Menu" << endl;
    cout << "1: Create new In-City Route" << endl;
    cout << "2: Create new City to City Route" << endl;
    cout << "3: View Current Routes" << endl;
    cout << "4: Exit" << endl;
    int choice = error(1,4);
    switch(choice){
        case 1:
            createInRoute();
            break;
        case 2:
            createC2CRoute();
        break;
        case 3:
            printLines();
            std::cout << "In city Routes: " << std::endl;
            for (const auto& entry : transLines) {
                std::cout << entry.first << std::endl;  // Print the key of transLines
            }
            printLines();
            std::cout << "City to City Routes: " << std::endl;
            for (const auto& entry : transC2CLines) {
                std::cout << entry.first << std::endl;  // Print the key of transC2CLines
            }
            newRouteMenu();
        break;
        case 4:
            editTransport();
        break;
    }
}

void createC2CRoute(){
    printLines();
    chooseFromMenu();
    std::cout << "Please select Transport Type:" << std::endl;
    std::cout << "1: Train Transport(Freight only)" << std::endl;
    std::cout << "2: Airplane Transport" << std::endl;
    int choice = error(1,2);
    switch(choice){
        case 1:{
            StructureGroup* startB = NULL;
            StructureGroup* endB = NULL;
            string transName = "";
            string routeName = "";
            std::cout << "List of Cities: "<< std::endl;
            printLines();
            for(size_t i = 0; i < arr.size(); i++){
                std::cout << i << ": " << arr[i]->getName() << std::endl;
            }
            printLines();
            std::cout << "Enter Starting City:" << std::endl;
            string word = stringError();
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i]->getName() == word){
                    startB = arr[i];
                }
            }
            printLines();
            std::cout << "Enter Ending City:" << std::endl;
            string word1 = stringError();
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i]->getName() == word1){
                    endB = arr[i];
                }
            }
            printLines();
            std::cout << "List of all Freight Train Transports: " << std::endl;
            printLines();
            std::cout << "Freight Train Transports:" << std::endl;
            for(size_t i = 0; i < TT.size(); i++){
                if (dynamic_cast<Freight*>(TT[i])) {
                    std::cout << i << ": " << TT[i]->getVehicle()->getName() << std::endl;
                }
            }
            std::cout << "Enter a Transport Name: " << std::endl;
            string tName = stringError();
            printLines();
            for(size_t i = 0; i < TT.size(); i++){
                if(TT[i]->getVehicle()->getName() == tName){
                    transName = tName;
                    break;
                }
            }
            std::cout << "Enter a route name: " << std::endl;
            routeName = stringError();
            printLines();
            if(transName == "" || routeName == "" ){
                std::cout << "Invalid Input, please review your inputs and try again" << std::endl;
                std::cout << "Transport Name: " << transName << std::endl;
                std::cout << "Route Name: " << routeName << std::endl;
                createC2CRoute();
            }
            else if(startB == NULL || endB == NULL){
                std::cout << "Invalid Input, no such start/end city exists" << std::endl;
                createC2CRoute();
            }
            else{
                printLines();
                createC2CTransportRoute(choice, startB, endB, transName, routeName);
                std::cout << "Route created!" << std::endl;
                newRouteMenu();
            }
        }
        break;
        case 2:{
            StructureGroup* startB = NULL;
            StructureGroup* endB = NULL;
            string transName = "";
            string routeName = "";
            std::cout << "List of Cities: "<< std::endl;
            printLines();
            for(size_t i = 0; i < arr.size(); i++){
                std::cout << i << ": " << arr[i]->getName() << std::endl;
            }
            printLines();
            std::cout << "Enter Starting City:" << std::endl;
            string word1 = stringError();
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i]->getName() == word1){
                    startB = arr[i];
                }
            }
            printLines();
            std::cout << "Enter Ending City:" << std::endl;
            string word2 = stringError();
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i]->getName() == word2){
                    endB = arr[i];
                }
            }
            printLines();
            std::cout << "List of all Airplane Transports: " << std::endl;
            printLines();
            std::cout << "Airplane Transports:" << std::endl;
            for(size_t i = 0; i < AT.size(); i++){
                std::cout << i << ": " << AT[i]->getVehicle()->getName() << std::endl;
            }
            std::cout << "Enter a Transport Name: " << std::endl;
            string tName = stringError();
            printLines();
            for(size_t i = 0; i < AT.size(); i++){
                if(AT[i]->getVehicle()->getName() == tName){
                    transName = tName;
                    break;
                }
            }
            std::cout << "Enter a route name: " << std::endl;
            routeName = stringError();
            printLines();
            if(transName == "" || routeName == "" ){
                std::cout << "Invalid Input, please review your inputs and try again" << std::endl;
                std::cout << "Transport Name: " << transName << std::endl;
                std::cout << "Route Name: " << routeName << std::endl;
                createC2CRoute();
            }
            else if(startB == NULL || endB == NULL){
                std::cout << "Invalid Input, no such start/end city exists" << std::endl;
                createC2CRoute();
            }
            else{
                printLines();
                createC2CTransportRoute(choice, startB, endB, transName, routeName);
                std::cout << "Route created!" << std::endl;
                newRouteMenu();
            }
        }
        break;
    }
}

void createInRoute(){
    printLines();
    chooseFromMenu();
    std::cout << "Please select Transport Type:" << std::endl;
    std::cout << "1: Public Transport" << std::endl;
    std::cout << "2: Train Transport" << std::endl;
    int choice = error(1,2);
    switch(choice){
        case 1:{
            int transType = choice;
            string cityName = "";
            BasicStructure* startB = NULL;
            BasicStructure* endB = NULL;
            string transName = "";
            string routeName = "";
            std::cout << "List of Cities: "<< std::endl;
            printLines();
            for(size_t i = 0; i < arr.size(); i++){
                std::cout << i << ": " << arr[i]->getName() << std::endl;
            }
            printLines();
            std::cout << "Enter City Name:" << std::endl;
            string word = stringError();
            printLines();
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i]->getName() == word){
                    cityName = word;
                    vector<Structure*> buildings = arr[i]->getChildren();
                    std::cout << "List of Structures in " << arr[i]->getName() << std::endl;
                    printLines();
                    for(size_t i = 0; i < buildings.size(); i++){
                        std::cout << i << ": " << buildings[i]->getName() << std::endl;
                    }
                    std::cout << "Enter start building: " << std::endl;
                    string start = stringError();
                    printLines();
                    for(size_t i = 0; i < buildings.size(); i++){
                        if(buildings[i]->getName() == start){
                            startB = dynamic_cast<BasicStructure*>(buildings[i]);
                            break;
                        }
                    }
                    std::cout << "Enter end building: " << std::endl;
                    string ending = stringError();
                    printLines();
                    for(size_t i = 0; i < buildings.size(); i++){
                        if(buildings[i]->getName() == ending){
                            endB = dynamic_cast<BasicStructure*>(buildings[i]);
                            break;
                        }
                    }
                    break;
                }
            }
            std::cout << "List of all Public Transports: " << std::endl;
            printLines();
            std::cout << "Public Transports:" << std::endl;
            for(size_t i = 0; i < PT.size(); i++){
                std::cout << i << ": " << PT[i]->getVehicle()->getName() << std::endl;
            }
            std::cout << "Enter a Transport Name: " << std::endl;
            string tName = stringError();
            printLines();
            for(size_t i = 0; i < PT.size(); i++){
                if(PT[i]->getVehicle()->getName() == tName){
                    transName = tName;
                    break;
                }
            }
            std::cout << "Enter a name for the route: " << std::endl;
            routeName = stringError();
            printLines();
            if(transType == 0 || cityName == "" || transName == "" || routeName == "" ){
                std::cout << "Invalid Input, please review your inputs and try again" << std::endl;
                std::cout << "City Name: " << cityName << std::endl;
                std::cout << "Transport Name: " << transName << std::endl;
                std::cout << "Route Name: " << routeName << std::endl;
                newRouteMenu();
            }
            else if(startB == NULL || endB == NULL){
                std::cout << "Invalid Input, no such start/end building exists" << std::endl;
                newRouteMenu();
            }
            else{
                printLines();
                createInCityTransportRoute(transType, cityName, startB, endB, transName, routeName);
                std::cout << "Route created!" << std::endl;
                newRouteMenu();
            }
        }
        break;
        case 2:{
            int transType = choice;
            string cityName = "";
            BasicStructure* startB = NULL;
            BasicStructure* endB = NULL;
            string transName = "";
            string routeName = "";
            std::cout << "List of Cities: "<< std::endl;
            printLines();
            for(size_t i = 0; i < arr.size(); i++){
                std::cout << i << ": " << arr[i]->getName() << std::endl;
            }
            printLines();
            std::cout << "Enter City Name:" << std::endl;
            string word = stringError();
            printLines();
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i]->getName() == word){
                    cityName = word;
                    vector<Structure*> buildings = arr[i]->getChildren();
                    std::cout << "List of Structures in " << arr[i]->getName() << std::endl;
                    printLines();
                    for(size_t i = 0; i < buildings.size(); i++){
                        std::cout << i << ": " << buildings[i]->getName() << std::endl;
                    }
                    std::cout << "Enter start building: " << std::endl;
                    string start = stringError();
                    printLines();
                    for(size_t i = 0; i < buildings.size(); i++){
                        if(buildings[i]->getName() == start){
                            startB = dynamic_cast<BasicStructure*>(buildings[i]);
                            break;
                        }
                    }
                    std::cout << "Enter end building: " << std::endl;
                    string ending = stringError();
                    printLines();
                    for(size_t i = 0; i < buildings.size(); i++){
                        if(buildings[i]->getName() == ending){
                            endB = dynamic_cast<BasicStructure*>(buildings[i]);
                            break;
                        }
                    }
                    break;
                }
            }
            std::cout << "List of all Train Transports: " << std::endl;
            printLines();
            std::cout << "Train Transports:" << std::endl;
            for(size_t i = 0; i < TT.size(); i++){
                std::cout << i << ": " << TT[i]->getVehicle()->getName() << std::endl;
            }
            std::cout << "Enter a Transport Name: " << std::endl;
            string tName = stringError();
            printLines();
            for(size_t i = 0; i < TT.size(); i++){
                if(TT[i]->getVehicle()->getName() == tName){
                    transName = tName;
                    break;
                }
            }
            std::cout << "Enter a route name: " << std::endl;
            routeName = stringError();
            printLines();
            if(transType == 0 || cityName == "" || transName == "" || routeName == "" ){
                std::cout << "Invalid Input, please review your inputs and try again" << std::endl;
                std::cout << "City Name: " << cityName << std::endl;
                std::cout << "Transport Name: " << transName << std::endl;
                std::cout << "Route Name: " << routeName << std::endl;
                createInRoute();
            }
            else if(startB == NULL || endB == NULL){
                std::cout << "Invalid Input, no such start/end building exists" << std::endl;
                createInRoute();
            }
            else{
                printLines();
                createInCityTransportRoute(transType, cityName, startB, endB, transName, routeName);
                std::cout << "Route created!" << std::endl;
                newRouteMenu();
            }
        }
        break;
    }
}

string stringError(){
    string word = "";
    std::regex validNamePattern("^[A-Za-z0-9\\s]+$"); // Allows letters, numbers, and spaces
    std::cin >> word;
    while (true) {
        // Check if road name matches the pattern and is not empty
        if (!word.empty() && std::regex_match(word, validNamePattern)) {
            break; // Valid road name; exit loop
        }
        std::cout << "Invalid name. Please enter a valid name (letters, numbers only):" << std::endl;
        std::cin.clear();
        std::cin >> word;
    }
    return word;
}

int error(int min, int max){
        int choice = 0;
            while (true) {
            std::cin >> choice;
            // Check if input failed (not a number) or if choice is out of range
            if (std::cin.fail() || choice < min || choice > max) {
                std::cout << "Invalid Option, please try again" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break; // Valid choice
            }
        }
        return choice;
}
void newTransportMenu(){
        printLines();
        chooseFromMenu();
        cout << "Transport Creation Menu" << endl;
        cout << "1: Create new Public Transport" << endl;
        cout << "2: Create new Train Transport" << endl;
        cout << "3: Create new Airplane Transport" << endl;
        cout << "4: View Current Transports" << endl;
        cout << "5: Exit" << endl;
        int choice = error(1,5);
        createTransportation(choice);
}

void createTransportation(int num){
    switch(num) {
        case 1: {
            printLines();
            chooseFromMenu();
            cout << "Public Transport Creation Menu" << endl;
            cout << "1: Create Bus" << endl;
            cout << "2: Create Taxi" << endl;
            cout << "3: Exit" << endl;
            int publicChoice = error(1, 3);
            switch(publicChoice) {
                case 1:
                    printLines();
                    chooseFromMenu();
                    std::cout << "Please provide a Bus name: " << std::endl;
                    createPublicType(1, stringError());
                    newTransportMenu();
                    break;
                case 2:
                    printLines();
                    chooseFromMenu();
                    std::cout << "Please provide a Taxi name: " << std::endl;
                    createPublicType(2, stringError());
                    newTransportMenu();
                    break;
                case 3:
                    editTransport();
                    break;
            } 
        }
        break;
        case 2: {
            printLines();
            chooseFromMenu();
            cout << "Train Transport Creation Menu" << endl;
            cout << "1: Create Metro" << endl;
            cout << "2: Create Freight" << endl;
            cout << "3: Exit" << endl;
            int trainChoice = error(1, 3);
            switch(trainChoice) {
                case 1:
                    printLines();
                    chooseFromMenu();
                    std::cout << "Please provide a Metro name: " << std::endl;
                    createTrainType(1, stringError());
                    newTransportMenu();
                    break;
                case 2:
                    printLines();
                    chooseFromMenu();
                    std::cout << "Please provide a Freight name: " << std::endl;
                    createTrainType(3, stringError());
                    newTransportMenu();
                    break;
                case 3:
                    editTransport();
                    break;
            }
        }
        break;
        case 3: {
            printLines();
            chooseFromMenu();
            cout << "Airplane Transport Creation Menu" << endl;
            cout << "1: Create Passenger Plane" << endl;
            cout << "2: Create Cargo Plane" << endl;
            cout << "3: Exit" << endl;
            int airChoice = error(1, 3);
            switch(airChoice) {
                case 1:
                    printLines();
                    chooseFromMenu();
                    std::cout << "Please provide a Passenger Plane name: " << std::endl;
                    createAirportType(1, stringError());
                    newTransportMenu();
                    break;
                case 2:
                    printLines();
                    chooseFromMenu();
                    std::cout << "Please provide a Cargo name: " << std::endl;
                    createAirportType(2, stringError());
                    newTransportMenu();
                    break;
                case 3:
                    editTransport();
                    break;
            }
            
        }
        break;
        case 4: {
            printLines();
            chooseFromMenu();
            std::cout << "Viewing Current Transports" << std::endl;
            printLines();
            std::cout << "Public Transports:" << std::endl;
            for(size_t i = 0; i < PT.size(); i++){
                std::cout << i << ": " << PT[i]->getVehicle()->getName() << std::endl;
            }
            printLines();
            std::cout << "Train Transports:" << std::endl;
            for(size_t i = 0; i < TT.size(); i++){
                std::cout << i << ": " << TT[i]->getVehicle()->getName() << std::endl;
            }
            printLines();
            std::cout << "Airplane Transports:" << std::endl;
            for(size_t i = 0; i < AT.size(); i++){
                std::cout << i << ": " << AT[i]->getVehicle()->getName() << std::endl;
            }
            newTransportMenu();
        }
        break;
        case 5:{
            editTransport();
        }
    }

}

void editTransportGroups(){
    //this will be between groups
    printLines();
    void chooseFromMenu();
    cout << "1: Add Transport from one area to another" << endl;
    cout << "2: Remove Transport from one area to another" << endl;
    cout << "3: Return" << endl;
    


}

void addTransportGroups(){
    printLines();
    //you might need to create a global tuple that will keep track of all these transport systems that we will be adding
    //you could have one for between groups and another for inbetween areas
    cout << "Enter the area you would like to add a transport system to" << endl;

    // get this input
    //validate that it is part of the structture. You can use a for loop to loop through the StructuresGroup array called "arr" and use the get name to check if the input is in that group
    //if not tell the user 
    //if yes continue

    cout << "Enter the structure group you would like to build a transport system to" << endl;
    //same user input validation

    //since its between groups you can use flight and railway 
    //add to the tuple
    
}

void removeTransportGroups(){
    printLines();
    //similar to add except remove at the end
}

void editTransportInGroups(){
    //similar to edit transport groups 
}

void addTransportInGroups(){
    //get structre group
    //check if structure group is there
    //get structure from.
    //check if its there 
    //get structure to 
    //check if its there
    //add to tuple
}

void removeTransportInGroups(){
    //similar to add except remove
}


//Add citizen
void addCitizens(){
    printLines();

    //Intro/Tutorial
    if(!citizenIntro)
    {
        int introChoice;

        cout << "Welcome to the add citizen system\n";
        cout << "Here you will add citizens to the area based on the buildings you have built\n";
        cout << "There are four different types of citizens, High-class citizens, Middle-class citizens, Low-class Citizens and Mayors\n";
        cout << "Each are separated by their income levels and the different services they offer\n";
        cout << "Each citizen has a satisfaction level that is affected by the taxes they are made to pay, the policies you decide to implement and the budget allocation changes you make\n";
        cout << "Enter 1 to continue\n";

        cin >> introChoice;

        while(introChoice != 1)
        {

            if(!(cin >> introChoice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "I dont think your ready to continue, try pressing 1 again.\n";
            }    
            else if(introChoice != 1)
            {
                cout << "\nI dont think your ready to continue, try pressing 1 again.\n";
            }
        }
        citizenIntro = true;
        cout << endl;

        printLines();
    }

    while(true)
    {
        chooseFromMenu();
        int citizenMenuChoice;
        cout << "1: Add citizens" << endl;
        cout << "2: Add mayor" << endl;
        cout << "3. See current population\n";
        cout << "4. Make citizens vote for the new mayor\n";
        cout << "5. See who is the current mayor\n";
        cout << "6. See current satisfaction level of citizens\n";
        cout << "7: Return" << endl;

        cin >> citizenMenuChoice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, Please enter a number between 1 and 7.\n";
        }

        //handle use input
        switch(citizenMenuChoice)
        {
            case 1:
                addCitizenToBuildings();
                break;
            case 2:
                addMayor();
                break;
            case 3:
                currentCitizenPopulation();
                break;
            case 4:
                makeCitizensVote();
                break;
            case 5:
                currentMayor();
                break;
            case 6:
                currentSatisfaction();
                break;
            case 7:
                mainMenu();
                return;
            default:
                cout << "Invalid choice inputted, please try again\n";
                break;
        }
    }
}
void addCitizenToBuildings()
{
    //Add citizen to a basicStructure, similar to add Mayor, first ask user which area and then how many

    printLines();

    //Ask user which type of citizens they would like to add
    while(true)
    {
        int typeCitizenChoice;
        cout << "\nWhich type of citizens would you like to add to the building\n";
        cout << "Note: the type of citizen you choose impacts maintainence costs and satisfaction\n";
        cout << "1. High-class citizens\n";
        cout << "2. Middle-class citizens\n";
        cout << "3. Low-class citizens\n";
        cout << "4. Return\n";

        cin >> typeCitizenChoice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, Please enter a number between 1 and 4.\n";
        }

        switch(typeCitizenChoice)
        {
            int amountCitizens;
            case 1:
            {
                cout << "How many high-class citizens do you want?\n";
                cin >> amountCitizens;

                //Add check to see if amount is more than structure capacity
                while(amountCitizens <= 0 || amountCitizens > 100000)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid number of citizens added, please try again\n";
                    }
                    else if(amountCitizens <= 0 || amountCitizens > 100000)
                    {
                        cout << "Invalid number of citizens added, please try again\n";
                    }
                    cin >> amountCitizens;
                }
                Citizen** highClassCitizenArr = new Citizen*[amountCitizens];
                Creator *highClassCreator = new HighCitizenCreator();

                for(int i = 0; i < amountCitizens; i++)
                {
                    highClassCitizenArr[i] = highClassCreator->specificCitizenOperation("employed", 75, nullptr);

                }
                //Add high-class citizens to structure, ask if correct
                addCititoBuild(amountCitizens);

                cout << "\n" <<amountCitizens << " of High-class citizens successfully added to the building\n";

                delete highClassCreator;
                break;
            }

            case 2:
            {
                cout << "How many middle-class citizens do you want\n";
                cin >> amountCitizens;

                //Add check to see if amount is more than structure capacity
                while(amountCitizens <= 0 || amountCitizens > 100000)
                {
                    if(!(cin >> amountCitizens))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid number of citizens added, please try again\n";
                    }
                    else if(amountCitizens <= 0)
                    {
                        cout << "Invalid number of citizens added, please try again\n";
                    }
                    cin >> amountCitizens;
                }
                Citizen** midClassCitizenArr = new Citizen*[amountCitizens];
                Creator *midClassCreator = new MiddleCitizenCreator();

                for(int i = 0; i < amountCitizens; i++)
                {
                    midClassCitizenArr[i] = midClassCreator->specificCitizenOperation("employed", 65, nullptr);

                }
                //Add mid-class citizen to structure, ask if correct
                addCititoBuild(amountCitizens);

                cout << "\n" <<amountCitizens << " of Middle-class citizens successfully added to the building\n";
                delete midClassCreator;
                break;
            }
            
            case 3:
            {
                cout << "How many low-class citizens do you want\n";
                cin >> amountCitizens;

                //Add check to see if amount is more than structure capacity
                while(amountCitizens <= 0 || amountCitizens > 100000)
                {
                    if(!(cin >> amountCitizens))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid number of citizens added, please try again\n";
                    }
                    else if(amountCitizens <= 0)
                    {
                        cout << "Invalid number of citizens added, please try again\n";
                    }
                    cin >> amountCitizens;
                }

                Citizen** lowClassCitizenArr = new Citizen*[amountCitizens];
                Creator *lowClassCreator = new LowCitizenCreator();

                for(int i = 0; i < amountCitizens; i++)
                {
                    lowClassCitizenArr[i] = lowClassCreator->specificCitizenOperation("employed", 55, nullptr);

                }
                //Add low-class citizen to structure, ask if correct
                addCititoBuild(amountCitizens);

                cout << "\n" <<amountCitizens << " of Low-class citizens successfully added to the building\n";
                delete lowClassCreator;
                break;
            }

            case 4:
                return;

            default:
                cout << "Invalid choice inputted, please try again\n";
                break;
        }
    }
}
void addMayor(){
    //this should add a mayor to a city group
    //we have a vector that keeps track of all the areas that have been created called arr however i have not crea
    printLines();

    string cityChoice;

    viewCity(); // this will print out all the city groups that have been created
    cout << "Enter the area you would like to add a mayor to" << endl;

    //get user input
    //validate that the area is there, consult view city to see how 

    while(true)
    {
        cin >> cityChoice;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid area inputted, please try again\n";
        }
        else if(!foundCity(cityChoice))
        {
            cout << "Invalid area inputted, please try again\n";
        }
        else
        {
            break;
        }
    }

    //Get index of city area
    int indexArea = getCityIndex(cityChoice);

    //Create actual mayor
    string newMayorName = "";
    cout << "Enter the name of the mayor\n";
    
    while(true)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newMayorName);

        if (newMayorName.empty() || regex_search(newMayorName, escape_characters)) {
            cout << "Invalid name entered, please try again\n";
            continue;
        }
        
        break;
    }

    MayorCreator *mc = new MayorCreator();
    mc->specificCitizenOperation("employed", 70, arr[indexArea], newMayorName);

    cout << endl;
    cout << newMayorName << " has been created\n";
    cout << "You can make all citizens vote for a mayor by going to the 'Make citizens vote for the new mayor' option\n";
    cout << endl;

    cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    delete mc;
}

//Helper function for add citizen and add mayor
bool foundCity(string city)
{
    if(city == "" || regex_search(city,escape_characters))
    {
        return false;
    }

    for(StructureGroup* g : arr)
    {
        if(city == g->getName())
        {
            return true;
        }
    }
    return false;
}
//Helper function for add citizen and add mayor
int getCityIndex(string city)
{
    int idx = 0;
    for(StructureGroup* g : arr)
    {
        if(city == g->getName())
        {
            return idx;
        }
        idx++;
    }
    return -1;
}
void currentCitizenPopulation()
{
    //-2 is for the sentinel nodes
    int currPop = Citizen::getPopulationCount()-2;
    previousPopulation = currPop - previousPopulation;

    cout << "\nThe current population of all cities is: " << currPop << endl;
    cout << endl;
}
int getCitizenPopulation()
{
    return Citizen::getPopulationCount()-2;
}
void makeCitizensVote()
{
    if(getCitizenPopulation() == 0)
    {
        cout << "No citizens have been added to your city. Please try adding citizens to your city before trying to get them to vote.\n";
        cout << endl;
        return;
    }
    votedOnce = true;
    CitizenIterator* iterate = SENTINEL->createCitizenIterator();

    while(!iterate->isDone())
    {
        iterate->currentItem()->vote();
        iterate->next();
    }

    int seeMayorResult;
    cout << "All citizens have now voted for their choice of mayor, Press 1 to see the results, press 2 to return\n";
    cin >> seeMayorResult;

    if(seeMayorResult == 2)
    {
        delete iterate;
        return;
    }

    while(seeMayorResult != 1)
    {
        if(!(cin >> seeMayorResult))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice inputted, please try again\n";
        }
    }

    delete iterate;
    
    currentMayor();
}
void currentMayor()
{
    if(!votedOnce)
    {
        cout << "\nYou never allowed your citizens vote yet, please allow them vote before seeing results\n";
        cout << endl;
        return;
    }
    Citizen::determineMayor();

    vector<Mayor*> mayors = SENTINEL_MAYOR->getMayors(); 

    bool noVotes = false;
    for(Mayor* m : mayors)
    {
        if(m->getVoteCount() > 0)
        {
            noVotes = true;
            break;
        }
    }

    //Mayors were created but citizens weren't
    if(noVotes == false)
    {
        cout << "No citizens have been added to the city, please add citizens before allowing them to vote\n";
        cout << endl;
        return;
    }

    MayorIterator* iterate = new MayorIterator(mayors);
    vector<Mayor*> electedMayors;

    while(!iterate->isDone())
    {
        if(iterate->currentItem()->getElectionStatus())
        {
            if(iterate->currentItem() != SENTINEL_MAYOR)
            {
                electedMayors.push_back(iterate->currentItem());
            }
        }
        iterate->next();
    }

    if(electedMayors.empty())
    {
        cout << "\nYou have not added any mayor to any area. Please add new mayors to the areas you have created before making your citizens vote\n";
        return;
    }


    for(Mayor* m : electedMayors)
    {
        cout << m->getMayorName() << " is the mayor for " << m->getHome()->getName() << " with " << m->getVoteCount() << " votes." << endl;
        cout << endl;
    }

    Citizen::resetVote();

    delete iterate;
}
void currentSatisfaction()
{
    if(getCitizenPopulation() == 0)
    {
        cout << "\nNo citizens have been added to your city. Please try adding citizens to your city before trying to get their satisfaction.\n\n";
        return;
    }

    double currSatisfaction = 0;
    AllCitizenIterator *iterate = SENTINEL->createCitizenIterator();
    
    while(!iterate->isDone())
    {
        currSatisfaction += iterate->currentItem()->getSatisfaction();
        iterate->next();
    }

    currSatisfaction = currSatisfaction/(Citizen::getPopulationCount()-2);
    previousSatisfaction = currSatisfaction - previousSatisfaction;

    cout << "\nThe current satisfaction of all citizens is " << currSatisfaction << endl;
    cout << endl;

    delete iterate;
}

void createPublicType(int type, string name){
    switch (type)
    {
        case 1:
            PT.push_back((new PublicTransport(new Bus(name))));
            std::cout << name <<" added successfully" << std::endl;
            break;
        case 2:
            PT.push_back(new PublicTransport(new Taxi(name)));
            std::cout << name <<" added successfully" << std::endl;
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
            std::cout << name <<" added successfully" << std::endl;
            break;
        case 2:
            TT.push_back(new TrainTransport(new Tram(name)));
            std::cout << name <<" added successfully" << std::endl;
            break;
        case 3:
            TT.push_back(new TrainTransport(new Freight(name)));
            std::cout << name <<" added successfully" << std::endl;
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
            std::cout << name <<" added successfully" << std::endl;
            break;
        case 2:
            AT.push_back(new AirportTransport(new Cargo(name)));
            std::cout << name <<" added successfully" << std::endl;
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

void createInCityTransportRoute(int TransType, const std::string& CityName, BasicStructure* starting, BasicStructure* ending, const std::string& transName, const std::string& routeName) {
    switch(TransType) {
        // Public Transport
        case 1: {
            for (PublicTransport* PublicTrans : PT) {
                if (PublicTrans->getVehicle()->getName() == transName) {
                    for (StructureGroup* Cities : arr) {
                        if (Cities->getName() == CityName) {
                            int startIdx = structureIndex(Cities, starting);
                            int endIdx = structureIndex(Cities, ending);

                            if (startIdx != -1 && endIdx != -1 && cityRoads.count(CityName)) {
                                auto& roads = cityRoads[CityName].first;
                                auto& roadSubjects = cityRoads[CityName].second;
                                std::vector<Transportation*> observers;

                                // Map structures to roads based on the 1-to-4 ratio
                                int startRoadIdx = startIdx / 4;
                                int endRoadIdx = endIdx / 4;

                                if (startRoadIdx <= endRoadIdx) {
                                    for (int i = startRoadIdx; i <= endRoadIdx; ++i) {
                                        observers.push_back(new ConcreteObserver(roads[i], PublicTrans));
                                        roadSubjects[i]->notify();
                                    }
                                } else {
                                    for (int i = startRoadIdx; i >= endRoadIdx; --i) {
                                        observers.push_back(new ConcreteObserver(roads[i], PublicTrans));
                                        roadSubjects[i]->notify();
                                    }
                                }
                                transLines.insert({routeName, observers});
                            }
                        } else {
                            std::cout << "No such City name" << std::endl;
                            return;
                        }
                    }
                } else {
                    std::cout << "No such Public Transport Name" << std::endl;
                    return;
                }
            }
            break;
        }

        // Train Transport
        case 2: {
            for (TrainTransport* TrainTrans : TT) {
                if (TrainTrans->getVehicle()->getName() == transName) {
                    for (StructureGroup* Cities : arr) {
                        if (Cities->getName() == CityName) {
                            int startIdx = structureIndex(Cities, starting);
                            int endIdx = structureIndex(Cities, ending);

                            if (startIdx != -1 && endIdx != -1 && cityRoads.count(CityName)) {
                                auto& roads = cityRoads[CityName].first;
                                auto& roadSubjects = cityRoads[CityName].second;
                                std::vector<Transportation*> observers;

                                // Map structures to roads based on the 1-to-4 ratio
                                int startRoadIdx = startIdx / 4;
                                int endRoadIdx = endIdx / 4;

                                if (startRoadIdx <= endRoadIdx) {
                                    for (int i = startRoadIdx; i <= endRoadIdx; ++i) {
                                        observers.push_back(new ConcreteObserver(roads[i], TrainTrans));
                                        roadSubjects[i]->notify();
                                    }
                                } else {
                                    for (int i = startRoadIdx; i >= endRoadIdx; --i) {
                                        observers.push_back(new ConcreteObserver(roads[i], TrainTrans));
                                        roadSubjects[i]->notify();
                                    }
                                }
                                transLines.insert({routeName, observers});
                            }
                        } else {
                            std::cout << "No such City name" << std::endl;
                            return;
                        }
                    }
                } else {
                    std::cout << "No such Train Transport Name" << std::endl;
                    return;
                }
            }
            break;
        }

        default:
            std::cout << "Incorrect Transport type" << std::endl;
            break;
    }
}

void createC2CTransportRoute(int transType, StructureGroup* starting, StructureGroup* ending, const std::string& transName, const std::string& routeName) {
    switch(transType) {
        // Train Transport
        case 1: {
            for (TrainTransport* TrainTrans : TT) {
                if (TrainTrans->getVehicle()->getName() == transName) {
                    Road* rail = new Road("UnderWaterRail");
                    Transportation* railObserver = new ConcreteObserver(rail, TrainTrans);
                    transC2CLines.insert({routeName, railObserver});
                }
            }
            break;
        }

        // Airplane Transport
        case 2: {
                for (AirportTransport* AirTrans : AT) {
                    if (AirTrans->getVehicle()->getName() == transName) {
                        Road* sky = new Road("Air");
                        Transportation* skyObserver = new ConcreteObserver(sky, AirTrans);
                        transC2CLines.insert({routeName, skyObserver});
                    }
                }
            break;
        }

        default:
            std::cout << "Incorrect Transport type" << std::endl;
            break;
    }
}

void RegularInCityTravel(int TransType, const std::string& CityName, BasicStructure* starting, BasicStructure* ending, const std::string& transName) {
    switch(TransType) {
        // Public Transport
        case 1: {
            for (PublicTransport* PublicTrans : PT) {
                if (PublicTrans->getVehicle()->getName() == transName) {
                    for (StructureGroup* Cities : arr) {
                        if (Cities->getName() == CityName) {
                            int startIdx = structureIndex(Cities, starting);
                            int endIdx = structureIndex(Cities, ending);
                            if (startIdx != -1 && endIdx != -1 && cityRoads.count(CityName)) {
                                auto& roads = cityRoads[CityName].first;
                                auto& roadSubjects = cityRoads[CityName].second;
                                std::vector<Transportation*> observers;

                                // Map structures to roads based on the 1-to-4 ratio
                                int startRoadIdx = startIdx / 4;
                                int endRoadIdx = endIdx / 4;

                                if (startRoadIdx <= endRoadIdx) {
                                    for (int i = startRoadIdx; i <= endRoadIdx; ++i) {
                                        observers.push_back(new ConcreteObserver(roads[i], PublicTrans));
                                        roadSubjects[i]->notify();
                                    }
                                } else {
                                    for (int i = startRoadIdx; i >= endRoadIdx; --i) {
                                        observers.push_back(new ConcreteObserver(roads[i], PublicTrans));
                                        roadSubjects[i]->notify();
                                    }
                                }
                                for(size_t i = 0; i < observers.size(); i++){
                                    observers[i]->travel();
                                }
                                
                            }
                        } else {
                            std::cout << "No such City name" << std::endl;
                            return;
                        }
                    }
                } else {
                    std::cout << "No such Public Transport Name" << std::endl;
                    return;
                }
            }
            break;
        }

        // Train Transport
        case 2: {
            for (TrainTransport* TrainTrans : TT) {
                if (TrainTrans->getVehicle()->getName() == transName) {
                    for (StructureGroup* Cities : arr) {
                        if (Cities->getName() == CityName) {
                            int startIdx = structureIndex(Cities, starting);
                            int endIdx = structureIndex(Cities, ending);

                            if (startIdx != -1 && endIdx != -1 && cityRoads.count(CityName)) {
                                auto& roads = cityRoads[CityName].first;
                                auto& roadSubjects = cityRoads[CityName].second;
                                std::vector<Transportation*> observers;

                                // Map structures to roads based on the 1-to-4 ratio
                                int startRoadIdx = startIdx / 4;
                                int endRoadIdx = endIdx / 4;

                                if (startRoadIdx <= endRoadIdx) {
                                    for (int i = startRoadIdx; i <= endRoadIdx; ++i) {
                                        observers.push_back(new ConcreteObserver(roads[i], TrainTrans));
                                        roadSubjects[i]->notify();
                                    }
                                } else {
                                    for (int i = startRoadIdx; i >= endRoadIdx; --i) {
                                        observers.push_back(new ConcreteObserver(roads[i], TrainTrans));
                                        roadSubjects[i]->notify();
                                    }
                                }
                                for(size_t i = 0; i < observers.size(); i++){
                                    observers[i]->travel();
                                }
                            }
                        } else {
                            std::cout << "No such City name" << std::endl;
                            return;
                        }
                    }
                } else {
                    std::cout << "No such Train Transport Name" << std::endl;
                    return;
                }
            }
            break;
        }

        default:
            std::cout << "Incorrect Transport type" << std::endl;
            break;
    }
}


void travelRoute(string routeName){
    vector<Transportation*> travelLine = transLines.find(routeName)->second;
    for(size_t i = 0; i < travelLine.size(); i++){
        travelLine[i]->travel();
    }
}

void travelC2CRoute(string routeName){
    Transportation* travelLine = transC2CLines.find(routeName)->second;
    travelLine->travel();
    
}
