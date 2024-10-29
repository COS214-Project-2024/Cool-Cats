#include <iostream>
#include <memory>

#include "MiddleCitizen.h"
#include "Mayor.h"
#include "Income.h"

using namespace std;

/// @brief Creates a new basic citizen object
MiddleCitizen::MiddleCitizen() : Citizen()
{
    middleClassCitizenCount++;
    income = new Income(10000, 19999, 4.5, 2);
}

/// @brief Creates a new middle-class citizen object
/// @param employmentStatus the employment status of the middle-class citizen, may only be either 'unemployed', 'employed', or 'self-employed' 
/// @param satisfaction the satisfaction of the high-class citizen, may only be between 0-100
/// @param home the home where the middle-class citizen lives
MiddleCitizen::MiddleCitizen(string employmentStatus, double satisfaction, shared_ptr<Structure> home) : Citizen(employmentStatus, satisfaction, home)
{
    middleClassCitizenCount++;
    income = new Income(10000, 19999, 4.5, 2);
}

/// @brief Allows a middle-class citizen to vote for their choice of mayor
void MiddleCitizen::vote()
{
    vector<Mayor*> mayors = Citizen::getMayors();

    cout << "Welcome Middle-Class citizen\n";
    cout << "Please choose the mayor you wish to vote for by typing the specific number associated with their name:\n";
    int index = 0;
    for(auto i = mayors.begin(); i != mayors.end(); i++)
    {
        cout << index << ". " << i[index]->getMayorName() << endl;
    }
    cout << endl;

    int choice = 0;
    cin >> choice;

    while(choice < 0 || choice > index)
    {
        cout << "Invalid choice, Please try again\n";
        cin >> choice;
    }

    mayors[choice]->receiveVote();

    cout << "Thank you for voting!\n";
}

/// @brief Static method that returns the number of active middle-class citizens in the city
/// @return number of middle-class citizens
int MiddleCitizen::getMiddleClassCitizenCount()
{
    return middleClassCitizenCount;
}

/// @brief Returns the income object of the specific middle-class citizen
/// @return the income object of the middle-class citizen
Income* MiddleCitizen::getIncome()
{
    return income;
}

//TO-DO
CitizenIterator* MiddleCitizen::createCitizenIterator()
{
    
}

MiddleCitizen::~MiddleCitizen()
{
    middleClassCitizenCount--;
    delete income;
}
