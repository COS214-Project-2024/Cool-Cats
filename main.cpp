#include <iostream>   // Include input-output stream library
#include <string>
#include <regex>

#include "Structure.h"
#include "StructureGroup.h"
#include "StructureDecorator.h"
#include "CStructIterator.h"
#include "SatisfactionEnhancer.h"
#include "MaintenanceCostReducer.h"
#include "ResourceEfficiencyEnhancer.h"
#include "BasicStructure.h"
#include "StructureIterator.h"

#include "Citizen/AllCitizenIterator.h"
#include "Citizen/Citizen.h"
#include "Citizen/CitizenIterator.h"
#include "Citizen/Creator.h"
#include "Citizen/HighCitizen.h"
#include "Citizen/HighCitizenCreator.h"
#include "Citizen/Income.h"
#include "Citizen/LowCitizen.h"
#include "Citizen/LowCitizenCreator.h"
#include "Citizen/Mayor.h"
#include "Citizen/MayorCreator.h"
#include "Citizen/MayorIterator.h"
#include "Citizen/MiddleCitizen.h"
#include "Citizen/MiddleCitizenCreator.h"

#include <limits>

using namespace std;

//gerneral funcitons:
void chooseFromMenu();


//for buildings:
void editStructureGroup();
void addStructureGroup();
void removeStructureGroup();

void editStructure();
void addStructure();
void removeStructure();


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
void addMayor();
vector<Citizen*> addCitizenToBuildings();
void currentCitizenPopulation();
void makeCitizensVote();
void currentMayor();
void currentSatisfaction();

//Global variables for Citizen
bool citizenIntro = false;
bool votedOnce = false;
int previousPopulation = 0;
double previousSatisfaction = 0;
Citizen * SENTINEL = new LowCitizen();
Mayor * SENTINEL_MAYOR = new Mayor();
regex escape_characters(R"(\\[nt\\\"'])");

//other

void errorMessage();
CStructIterator* createIteratorForGroup(StructureGroup* s );
void exit();
void viewCity(vector<StructureGroup*> s);

StructureGroup* createCityHall();

void createGovernment();



void editTransport();
void printLines();
void addMayor();

vector<StructureGroup*> arr; // this keeps track of all the stucture groups that have been created
vector<CStructIterator*> iteratorArr ; // this keeps track of iterators that have been created ie each structure is in a structure group and we can iterate over each structure in each structure group through this.


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
        //createGovernment();
    }
    printLines();
    cout << "Great you have created the city hall and government. From here on out there will be an option to view details of your city :)" << endl;
    bool cond = true;

    

    //this will be our main screen

    //When a user click one of these numbers, then they should be able to stuff based on the number added
    //we will need to do some error handling here
    //we use a while loop so whenever we break from one of the cases so that this menu will get shown after
    //You can printlines if you would like to seperate for clarity
    //You can exit to end program


    while(cond){
        printLines();
        cout << "1 : Edit Structure groups" << endl;
        cout << "2 : Edit Structures" << endl;
        cout << "3 : View City" << endl;
        cout << "4 : Exit" << endl;
        cout << "5 : Edit Transport" << endl;
        cout << "6 : Edit Government" << endl;
        cout << "7 : Add utilities" << endl;
        cout << "8 : Add citizens" << endl;
        cout << "Select NUMBER: ";

        cin >> option;

        switch (option){
            case 1:
                cout << "We got here" << endl;
                editStructureGroup();
                break;
            case 2:
                editStructure();
                break;
            case 3:
                viewCity(arr);
                break;
            case 4:
                exit();
                cond = false;
                break;
            case 5:
                editTransport();
                break;
            case 6:
                //Edit Government

                break;
            case 7:
                //Add utilities
                break;
            case 8:
                addCitizens();
                break;
            default:
                errorMessage();
        }
        printLines();


 

    }

    return 0;
}

//general funcitons

void printLines(){
    cout << "---------------------------------------------------------------" << endl;
}

void errorMessage(){

}

void exit(){
    viewCity(arr);
    // exit(1);
    // cout << "We got here" << endl;

}

void viewCity(vector<StructureGroup*> arr){
    printLines();
    for(StructureGroup* str : arr){
        printLines();
        std::cout << str->getName() << endl;
        
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
    BasicStructure* cityHall = new BasicStructure("CityHall", "Type1", 100, 100, 100, 100);
    cityhallGroup->add(cityHall);

    return cityhallGroup;
}

void createGovernment(){
    
}

void chooseFromMenu(){
    cout << "Choose from the menu" << endl;
}



//building funcitons
void editStructureGroup(){

    //this will allow us to add and remove structure groups from the array

    int option;
    printLines();
    cout << "Edit structure group Menu" << endl;

    cout << "1: Add" << endl;
    cout << "2: remove" << endl;
    cout << "3: view city" << endl;
    cout << "4: return to main" << endl;
    //add more if you see fit

    cin >> option; //get input from user

    //handle cases here
    //also note you will need to create a new iterator for this .There is an vector for iterator which we will use a 1:1 location for the iterator and groups array. SO position 1 of the iterator will correspond to group in postion 1 of the structure group.


    printLines();

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
}

void removeStructureGroup(){
    //this will remove a structure group to the vector arr
    //make sure after something is removed, the vector postion doesnt become empty and everything ahead is brought back.
}

void editStructure(){

    int option;
    printLines();
    cout << "Edit structure group Menu" << endl;

    cout << "1: Add" << endl;
    cout << "2: remove" << endl;
    cout << "3: view city" << endl;
    cout << "4: return to main" << endl;
    //add more if you see fit

    cin >> option; //get input from user

    //handle cases here
    //also note you will need to create a new iterator for this .There is an vector for iterator which we will use a 1:1 location for the iterator and groups array. SO position 1 of the iterator will correspond to group in postion 1 of the structure group.


    printLines();
    

    


}

void addStructure(){
    //ask the user for the group you would like 
    //then check if that group is available if not send a message and have them retype the name. 
    //if the name is correct then get the name of the structrue they would want to create
    //get the type
    //get the capacity
    //call the constructor of creating structures
    //add this new structure to the group
    //NB print view city wont work at the moment as i have not added a print structures to the view city its still just structure groups

    //feel free to add whatever you think is best

    //some demo code that i was working on before however its not really what i want anymore so feel free to look at it for inspiration but the psuedo is more better
    printLines();
    cout << "Please type the name of the are you would like to add the structure group you would like to add a structure to: " << endl;

    viewCity(arr);

    string option;
    cout << "Enter name Here: ";
    cin >> option;
    int index = 0;
    bool cond = false;
    for(int i = 0; i < static_cast<int>(arr.size()); i++){
        cout << "we got here " << endl;
        if(arr[i]->getName() == option){
            cond = true;

            index = i;
        }
    }

    if(cond == false){
        cout << "No such area exists" << endl;
    }
    else{
        cout << "Area is available !! " << endl;
        printLines();
        cout << "Enter the name of the structure you would like to add: ";
        cin >> option;

        printLines();
        int option2;
        char type;

        while(cond){
            cout << "Enter the type of struture you would like your structure to be. This type will affect how it will be treated as an industry will be different from a residential area" << endl;
            cout << "Choose from the Menu: " << endl;
            cout << "1: Residential" << endl;
            cout << "2: Commercial" << endl;
            cout << "3: Industrial" << endl;
            cout << "4: Landmarks" << endl;
            cin >> option2;

            switch (option2)
            {
            case 1:
                type = 'R';
                break;
            case 2:
                type = 'C';
                break;
            case 3:
                type = 'I';
                break;
            case 4 :
                type = 'L';
                break;

            
            default:
                break;
            }

            printLines();
            bool conditionForCapacity = true;
            int optionForCapacity;
            while(conditionForCapacity){
                cout << "To finalise creation of structure you will now need to select add capcity" << endl;
                cout << "Make sure that your value is a whole number greater than 0 but smaller than 1001" << endl;
                cin >> optionForCapacity;

                if(cin.fail()){

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                conditionForCapacity = false;
                cond = false;
                cin >> option2;

            }
            
        }
        


    }
}

void removeStructure(){
    //will work similar to add except remove is used instead.
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
void addCitizen(){
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
            cout << "I dont think your ready to continue, try pressing 1 again";
            cin >> introChoice;    
        }
        citizenIntro = true;
        cout << endl;
    }

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
            return;
        default:
            while(citizenMenuChoice < 1 || citizenMenuChoice > 7)
            {
                cout << "Invalid choice inputted, please try again\n";
                cin >> citizenMenuChoice;
            }

    }
}

//Ask KTO how to add a citizen to a basic structure
//parameter?
void addCitizensToBuildings()
{
    //Add citizen to a basicStructure, similar to add Mayor, first ask user which area and then how many

    printLines();

    string cityChoice;
    viewCity(arr);
    cout << "Enter the area you would like to add citizens to\n";

    cin >> cityChoice;

    while(!foundCity(cityChoice))
    {
        cout << "Invalid choice inputted, please try again\n";
        cin >> cityChoice;
    }
    int indexArea = getCityIndex(cityChoice);

    //Ask user which type of citizens they would like to add
    int typeCitizenChoice;
    cout << "Which type of citizens would you like to add to the building\n";
    cout << "Note: the type of citizen you choose impacts maintainence costs and satisfaction\n";
    cout << "1. High-class citizens\n";
    cout << "2. Middle-class citizens\n";
    cout << "3. Low-class citizens\n";
    cout << "4. Return\n";

    switch(typeCitizenChoice)
    {
        int amountCitizens;
        case 1:
            cout << "How many high-class citizens do you want?\n";
            cin >> amountCitizens;

            //Add check to see if amount is more than structure capacity
            while(amountCitizens < 0)
            {
                cout << "Invalid number of citizens added, please try again\n";
                cin >> amountCitizens;
            }
            Citizen** highClassCitizenArr = new Citizen*[amountCitizens];
            Creator *highClassCreator = new HighCitizenCreator();

            for(int i = 0; i < amountCitizens; i++)
            {
                highClassCitizenArr[i] = highClassCreator->specificCitizenOperation("employed", 75, existingStructure);

                //Add high-class citizens to structure, ask if correct
                // existingStructure.addCitizen(highClassCitizenArr[i]);
            }

            cout << amountCitizens << " of High-class citizens successfully added to the building\n";

            delete highClassCreator;
            break;

        case 2:
            cout << "How many middle-class citizens do you want\n";
            cin >> amountCitizens;

            //Add check to see if amount is more than structure capacity
            while(amountCitizens < 0)
            {
                cout << "Invalid number of citizens added, please try again\n";
                cin >> amountCitizens;
            }

            Citizen** midClassCitizenArr = new Citizen*[amountCitizens];
            Creator *midClassCreator = new MiddleCitizenCreator();

            for(int i = 0; i < amountCitizens; i++)
            {
                midClassCitizenArr[i] = midClassCreator->specificCitizenOperation("employed", 65, existingStructure);

                //Add mid-class citizen to structure, ask if correct
                // existingStructure.addCitizen(midClassCitizenArr[i]);
            }

            cout << amountCitizens << " of Middle-class citizens successfully added to the building\n";
            delete midClassCreator;
            break;
        
        case 3:
            cout << "How many low-class citizens do you want\n";
            cin >> amountCitizens;

            //Add check to see if amount is more than structure capacity
            while(amountCitizens < 0)
            {
                cout << "Invalid number of citizens added, please try again\n";
                cin >> amountCitizens;
            }

            Citizen** lowClassCitizenArr = new Citizen*[amountCitizens];
            Creator *lowClassCreator = new LowCitizenCreator();

            for(int i = 0; i < amountCitizens; i++)
            {
                lowClassCitizenArr[i] = lowClassCreator->specificCitizenOperation("employed", 55, existingStructure);

                //Add low-class citizen to structure, ask if correct
                // existingStructure.addCitizen(lowClassCitizenArr[i]);
            }

            cout << amountCitizens << " of Low-class citizens successfully added to the building\n";
            delete lowClassCreator;
            break;

        case 4:
            return;

        default:
            while(typeCitizenChoice < 1 || typeCitizenChoice > 4)
            {
                cout << "Invalid choice inputted, please try again\n";
                cin >> typeCitizenChoice;
            }
    }
}

//Ask KTO if I need to add mayor to a specific building
void addMayor(){
    //this should add a mayor to a city group
    //we have a vector that keeps track of all the areas that have been created called arr however i have not crea
    printLines();

    string cityChoice;

    viewCity(arr); // this will print out all the city groups that have been created
    cout << "Enter the area you would like to add a mayor to" << endl;

    //get user input
    //validate that the area is there, consult view city to see how 
    cin >> cityChoice;

    while(!foundCity(cityChoice))
    {
        cout << "Invalid choice inputted, please try again\n";
        cin >> cityChoice;
    }

    //Get index of city area
    int indexArea = getCityIndex(cityChoice);

    //Create actual mayor
    string newMayorName = "";
    cout << "Enter the name of the mayor\n";
    cin >> newMayorName;

    while(newMayorName == " " || regex_search(newMayorName, escape_characters))
    {
        cout << "Invalid name inputted, please try again\n";
        cin >> newMayorName;
    }

    MayorCreator *mc;
    Citizen *newMayor = mc->specificCitizenOperation("employed", 70, arr[indexArea], newMayorName);

    cout << newMayorName << " has been created\n";
    cout << "You can make all citizens vote for a mayor by going to the 'Make citizens vote for the new mayor' option\n";
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

    cout << "The current population of all cities is: " << currPop << endl;
}
void makeCitizensVote()
{
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
        cout << "Invalid choice inputted, please try again\n";
        cin >> seeMayorResult;
    }

    delete iterate;
    
    currentMayor();
}
void currentMayor()
{
    if(!votedOnce)
    {
        cout << "You have not made your citizens vote yet, please make them vote before seeing results\n";
        return;
    }
    Citizen::determineMayor();

    vector<Mayor*> mayors = SENTINEL_MAYOR->getMayors(); 
    MayorIterator* iterate = new MayorIterator(mayors);
    vector<Mayor*> electedMayors = SENTINEL_MAYOR->getMayors(); 

    while(!iterate->isDone())
    {
        if(iterate->currentItem()->getElectionStatus())
        {
            electedMayors.push_back(iterate->currentItem());
        }
        iterate->next();
    }

    for(Mayor* m : electedMayors)
    {
        cout << m->getMayorName() << " is the mayor for " << m->getHome() << " with " << m->getVoteCount() << endl;
    }

    delete iterate;
}
void currentSatisfaction()
{
    double currSatisfaction = 0;
    CitizenIterator *iterate = SENTINEL_MAYOR->createCitizenIterator();
    
    while(!iterate->isDone())
    {
        currSatisfaction += iterate->currentItem()->getSatisfaction();
        iterate->next();
    }

    currSatisfaction = currSatisfaction/(Citizen::getPopulationCount()-2);
    previousSatisfaction = currSatisfaction - previousSatisfaction;

    cout << "The current satisfaction of all citizens is " << currSatisfaction << endl;

    delete iterate;
}