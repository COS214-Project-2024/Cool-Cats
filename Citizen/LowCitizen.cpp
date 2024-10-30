#include <iostream>
#include <memory>

#include "LowCitizen.h"
#include "Mayor.h"
#include "Income.h"
#include "AllCitizenIterator.h"

using namespace std;

int LowCitizen::lowClassCitizenCount = 0;

/// @brief Creates a new basic low-class citizen object
LowCitizen::LowCitizen() : Citizen()
{
    lowClassCitizenCount++;
    income = new Income(0, 10000, 2.5, 1);
}

/// @brief Creates a new low-class citizen object
/// @param employmentStatus the employment status of the low-class citizen, may only either 'employed', 'unemployed', or 'self-employed'
/// @param satisfaction the satisfaction of the low-class citizen, may only be between 0-100
/// @param home the home where the low-class citizen lives
LowCitizen::LowCitizen(string employmentStatus, double satisfaction, shared_ptr<Structure> home) : Citizen(employmentStatus, satisfaction, home)
{
    lowClassCitizenCount++;
    income = new Income(0, 10000, 2.5, 1);
}

/// @brief Allows a low-class citizen to vote for their choice of mayor
void LowCitizen::vote()
{
    vector<Mayor*> mayors = Citizen::getMayors();

    cout << "Hi Low-Class citizen citizen\n";
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
int LowCitizen::getLowClassCitizenCount()
{
    return lowClassCitizenCount;
}

/// @brief Returns the income object of the specific middle-class citizen
/// @return the income object of the middle-class citizen
Income* LowCitizen::getIncome()
{
    return income;
}

/// @brief Returns an all citizen iterator object that allows a user to iterate through all citizens, regardless of type
/// @return An AllCitizenIterator object
CitizenIterator* LowCitizen::createCitizenIterator()
{
    return new AllCitizenIterator(citizens);
}

LowCitizen::~LowCitizen()
{
    lowClassCitizenCount--;
    delete income;
}