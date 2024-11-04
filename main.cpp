#include <iostream>   // Include input-output stream library
#include <string>
#include <vector>


#include "Structure.h"
#include "StructureGroup.h"
#include "StructureDecorator.h"
#include "CStructIterator.h"
#include "SatisfactionEnhancer.h"
#include "MaintenanceCostReducer.h"
#include "ResourceEfficiencyEnhancer.h"
#include "BasicStructure.h"
#include "StructureIterator.h"
#include "PowerUtility.h"
#include "WaterUtility.h"
#include "WasteUtility.h"
#include "SewageUtility.h"

#include <limits>

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

void addCititoBuild(Citizen* c);
void decorateStructure();


//for transport
void editTransport();

void editTransportGroups();
void addTransportGroups();
void removeTransportGroups();

void editTransportInGroups();
void addTransportInGroups();
void removeTransportInGroups();


//for citizens
void addCitizens();



//other

void errorMessage();
CStructIterator* createIteratorForGroup(StructureGroup* s );
void exit();
void viewCity();

StructureGroup* createCityHall();

void createGovernment();



void editTransport();
void printLines();
void addMayor();

vector<StructureGroup*> arr; // this keeps track of all the stucture groups that have been created
vector<CStructIterator*> iteratorArr ; // this keeps track of iterators that have been created ie each structure is in a structure group and we can iterate over each structure in each structure group through this.

//decorations
void printOption(const string& icon, const string& color, const string& text);

const string RESET_COLOR = "\033[0m";
const string RED_COLOR = "\033[1;31m";
const string GREEN_COLOR = "\033[1;32m";
const string YELLOW_COLOR = "\033[1;33m";
const string BLUE_COLOR = "\033[1;34m";
const string MAGENTA_COLOR = "\033[1;35m";
const string CYAN_COLOR = "\033[1;36m";

void printOption(const string& icon, const string& color, const string& text) {
    cout << color << icon << " " << text << RESET_COLOR << endl;
}

int main(){
    cout << "WELCOME TO THE COOL CATS CITY SIMULATOR" << endl;

    cout << "-------------------------------------------" << endl;

    cout << "We will need to start by creating the city hall, this a deafult standard and the government will be created as well. If you want to make changes to government options will appear as you build the city :)" << endl;

    cout << "Press 1 to create City hall and government" << endl;

    //NB City hall and Government are created by default.s

    //utilites for this should be added
    int option;
    cin >> option;
    if(option != 1){
        return 0;
    }
    else{


        arr.push_back(createCityHall());
        iteratorArr.push_back(createIteratorForGroup(arr.front())); // potential erros can arise from here
        createGovernment();
    }
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
        printOption("🏗️", BLUE_COLOR, "1 : Edit Structure Groups");
        printOption("🏢", GREEN_COLOR, "2 : Edit Structures");
        printOption("🌆", CYAN_COLOR, "3 : View City");
        printOption("🚪", RED_COLOR, "4 : Exit");
        printOption("🚋", YELLOW_COLOR, "5 : Edit Transport");
        printOption("🏛️", MAGENTA_COLOR, "6 : Edit Government");
        printOption("🔌", BLUE_COLOR, "7 : Add Utilities");
        printOption("👥", GREEN_COLOR, "8 : Add Citizens");
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
            }
        }

        delete iterator; // Clean up iterator
        printLines();
    }

    //printLines();
}

CStructIterator* createIteratorForGroup(StructureGroup* s ){
    CStructIterator *newIterator = s->createIterator();
    return newIterator;
}

StructureGroup* createCityHall(){
    //this is default created, so its done in the before the main menu
    StructureGroup * cityhallGroup = new StructureGroup("CityHallGroup");
    BasicStructure* cityHall = new BasicStructure("CityHall", 'L',100);
    cityhallGroup->add(cityHall);

    return cityhallGroup;
}

void createGovernment(){
    
}

void chooseFromMenu(){
    cout << "Choose from the menu" << endl;
}



//building funcitons

//function to add citizen to building:
void addCititoBuild(Citizen* c) {
    if (!c) {
        throw std::invalid_argument("Citizen cannot be null.");
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
                    basicStructure->addcitizen(c);
                    cout << "Citizen added successfully to " << buildingName << "." << endl;
                } catch (const std::exception& e) {
                    cout << "Error adding citizen: " << e.what() << endl;
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
        printOption("➕", GREEN_COLOR, "1: Add");
        printOption("➖", RED_COLOR, "2: Remove");
        printOption("👀", CYAN_COLOR, "3: View City");
        printOption("🔙", YELLOW_COLOR, "4: Return to Main Menu");
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


    //printLines();

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
        cout << "Edit Structure Menu" << endl;
        printOption("➕", GREEN_COLOR, "1: Add");
        printOption("➖", RED_COLOR, "2: Remove");
        printOption("👀", CYAN_COLOR, "3: View City");
        printOption("🔙", YELLOW_COLOR, "4: Return to Main Menu");
        printOption("🔄", BLUE_COLOR, "5: Update Structures");
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

    int groupIndex;
    cout << "Enter the index of the Structure group: ";
    while ( !(cin >> groupIndex) || groupIndex < 0 || groupIndex >= arr.size()) {
        cout << "Invalid input. Please enter a valid group index. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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



    
    arr[groupIndex]->add(newStructure);

    CStructIterator* newIterator = arr[groupIndex]->createIterator();

    cout << "Structure added. Available structures in area \"" << arr[groupIndex]->getName() << "\":" << endl;
    for (newIterator->first(); !newIterator->isDone(); newIterator->next()){
        Structure* structure = newIterator->currentItem();
        if (structure){
            cout << "- " << structure->getName() << endl;
        }
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

    int groupIndex;
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

        // switch (decorationOption) {
        //     case 1:
        //         selectedStructure = new SatisfactionEnhancer(selectedStructure);
        //         break;
        //     case 2:
        //         selectedStructure = new ResourceEfficiencyEnhancer(selectedStructure);
        //         break;
        //     case 3:
        //         selectedStructure = new MaintenanceCostReducer(selectedStructure);
        //         break;
        //     default:
        //         cout << "Invalid decoration option." << endl;
        //         return;
        // }
    }
}



//Transport functions
void editTransport(){
    //return
    //add transport route from one place to another and mode
    printLines();
    chooseFromMenu();
    cout << "Transport Menu" << endl;
    cout << "1: Edit Transport from one city group to another city group" << endl;
    cout << "2: Edit Transport in a city" << endl;
    cout << "3: Return" << endl;
    cout << "4: view city" << endl;

    //get user input and from there call the function required for that
    //view city has already be implemented for city groups it will still need to be implemented for structures

    //we will need to get input from the user, ie from what place to what place. 
    //three things will need to be shown here:
        //how the observer will notify 
        //how we use state to consider which form of transportation route to create, maybe we could use the capacity of the structure group to determine what transport options are available 
    
    cout << "Enter the structure group you would like to build transport system from" << endl;
    
    
    

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
    chooseFromMenu();
    cout << "1: Add citizens" << endl;
    cout << "2: Add mayor" << endl;
    cout << "3: return" << endl;

    //handle use input
}

void addMayor(){
    //this should add a mayor to a city group
    //we have a vector that keeps track of all the areas that have been created called arr however i have not crea
    printLines();
    viewCity(); // this will print out all the city groups that have been created
    cout << "Enter the area you would like to add a mayor to" << endl;

    //get user input
    //validate that the area si there, consult view city to see how 


}