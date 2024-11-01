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

using namespace std;
void errorMessage();
CStructIterator* createIteratorForGroup();
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
CStructIterator *cityHallIterator ;


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
        cityHallIterator = createIteratorForGroup(arr.front()); // potential erros can arise from here
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
        cout << "5 :Edit structure" << endl;
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