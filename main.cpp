#include <iostream>   // Include input-output stream library
#include <string>

#include "Structure.h"
#include "StructureGroup.h"
#include "StructureDecorator.h"
#include "CStructIterator.h"
#include "SatisfactionEnhancer.h"
#include "MaintenanceCostReducer.h"
#include "ResourceEfficiencyEnhancer.h"
#include "BasicStructure.h"
#include "StructureIterator.h"

#include <limits>

using namespace std;
void errorMessage();
CStructIterator* createIteratorForGroup(StructureGroup* s );
void exit();
void viewCity(vector<StructureGroup*> s);

StructureGroup* createCityHall();

void createGovernment();

void createStructureGroup();
void createStructure();

void addTransport();
void printLines();
void addMayor();

vector<StructureGroup*> arr;
vector<CStructIterator*> iteratorArr ;


int main(){
    cout << "WELCOME TO THE COOL CATS CITY SIMULATOR" << endl;

    cout << "-------------------------------------------" << endl;

    cout << "We will need to start by creating the city hall, this a deafult standard and the government will be created as well. If you want to make changes to government options will appear as you build the city :)" << endl;

    cout << "Press 1 to create City hall and government" << endl;

    

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

    
    while(cond){
        printLines();
        cout << "1 : Create new area" << endl;
        cout << "2 : Create Structure " << endl;
        cout << "3 : View City" << endl;
        cout << "4 : Exit" << endl;
        cout << "5 : Edit structure" << endl;
        cout << "Select NUMBER: ";

        cin >> option;

        switch (option){
            case 1:
                createStructureGroup();
                break;
            case 2:
                createStructure();
                break;
            case 3:
                viewCity(arr);
                break;
            case 4:
                exit();
                cond = false;
                break;
            default:
                errorMessage();
        }
        printLines();


 

    }

    return 0;
}

void printLines(){
    cout << "---------------------------------------------------------------" << endl;
}

void errorMessage(){

}

void exit(){
    viewCity(arr);
    exit(1);

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

    StructureGroup * cityhallGroup = new StructureGroup("CityHallGroup");
    BasicStructure* cityHall = new BasicStructure("CityHall", "Type1", 100, 100, 100, 100);
    cityhallGroup->add(cityHall);

    return cityhallGroup;
}

void createGovernment(){
    
}

void createStructureGroup(){

    //road from main hall is created in the background
    printLines();
    string name;
    cout << "Enter Name of area you would like to add" << endl;
    cin >> name;

    StructureGroup* newStructureGroup = new StructureGroup(name);
    arr.push_back(newStructureGroup);

    printLines();
    
    cout << "YOU have created a new area: " << name << endl;

    
    bool cond = true;
    while(cond){
        printLines();

        cout << "Menu" << endl;
        cout << "1: Create Transport system" << endl;
        cout << "2: Return back" << endl;
        cout << "3: Add mayor" << endl;
        cout << "4: Exit" << endl;
        cout << "5: View City" << endl;

        int option;
        cout << "Select NUMBER: ";
        cin>> option;
        switch (option){
            case 1:
            addTransport();
        break;
        case 2:
            return;
            break;

        case 3:
            addMayor();
            break;
    
        case 4:
            exit();
            break;
        case 5:
            viewCity(arr);
            break;
        default:
            break;
        }
    }
    
    
    //need to be able to go back
    //create trasport system
    //add mayor
    
    //utilities are added 

}
void createStructure(){
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




    //configure government should be allowed
    //add citizens
    //add decorator
    //add transport
    //return to structure group 
    //exit
    //error handling
}

void addTransport(){
    //return
    //add transport route from one place to another and mode

}

void additizen(){
    //return
    //citizen satisfaction 
    //no of citizens
    //etc
}

void addMayor(){

}