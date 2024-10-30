#include <iostream>   // Include input-output stream library
#include <string>

using namespace std;
void errorMessage();

void exit();
void viewCity();

void createCityHall();

void createGovernment();

void createStructureGroup();
void createStructure();

void addTransport();
void printLines();

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
        createCityHall();
        createGovernment();
    }
    printLines();
    cout << "Great you have created the city hall and government. From here on out there will be an option to view details of your city :)" << endl;
    bool cond = true;
    while(cond){
        cout << "1 : Create Structure group" << endl;
        cout << "2 : Create Structure " << endl;
        cout << "3 : View City" << endl;
        cout << "4 : Exit" << endl;

        cin >> option;

        switch (option){
            case 1:
                createStructureGroup();
                break;
            case 2:
                createStructure();
                break;
            case 3:
                viewCity();
                break;
            case 4:
                exit();
                cond = false;
                break;
            default:
                errorMessage();
        }


 

    }

    return 0;
}

void printLines(){
    cout << "---------------------------------------------------------------" << endl;
}

void errorMessage(){

}

void exit(){
    
}
void viewCity(){

}

void createCityHall(){

}

void createGovernment(){
    
}

void createStructureGroup(){

    //need to be able to go back
    //create trasport system
    //add mayor
    //road from main hall is created in the background
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