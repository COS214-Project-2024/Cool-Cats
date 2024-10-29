#include <iostream>
#include <memory>
#include <vector>

#include "HighCitizen.h"
#include "Mayor.h"

using namespace std;

/// @brief Creates a new basic citizen object
HighCitizen::HighCitizen() : Citizen()
{
    highClassCitizenCount++;
    income = new Income(20000, 1000000, 3.5, 1);
}

/// @brief Creates a new high-class citizen object
/// @param employmentStatus the employment status of the high-class citizen, may only be either 'unemployed', 'employed' or 'self-employed'
/// @param satisfaction the satisfaction of the high-class citizen, may only be between 0-100
/// @param home the home where the high-class citizen lives
HighCitizen::HighCitizen(string employmentStatus, double satisfaction, shared_ptr<Structure> home) : Citizen(employmentStatus, satisfaction, home)
{
    highClassCitizenCount++;
    income = new Income(6000, 10000, 3.5, 1);
}

/// @brief Allows a high-class citizen to vote for their choice of mayor
void HighCitizen::vote()
{
    vector<Mayor*> mayors = Citizen::getMayors();

    cout << "Salutation High-Class citizen\n";
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

/// @brief Static method that returns the number of active high class citizens in the city
/// @return number of high class citizens
int HighCitizen::getHighClassCitizenCount()
{
    return highClassCitizenCount;
}

/// @brief Returns the income object of the specific high-class citizen
/// @return the income object of the high-class citizen
Income* HighCitizen::getIncome()
{
    return income;
}


//TO-DO
CitizenIterator* HighCitizen::createCitizenIterator()
{

}

HighCitizen::~HighCitizen()
{
    highClassCitizenCount--;
    delete income;
}