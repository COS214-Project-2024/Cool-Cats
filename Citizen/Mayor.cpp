#include <iostream>
#include <memory>

#include "Mayor.h"
#include "MayorIterator.h"

using namespace std;

int Mayor::MayorCount = 0;

/// @brief Creates a new basic mayor, with them not being elected and having 0 votes
Mayor::Mayor() : Citizen() 
{ 
    name = "Mayor " + (++MayorCount);
    electedMayor = false;
    voteCount = 0;
    income = new Income(10000, 15000, 5.5, 2.5);
};

//Helper function
bool isValidName(const string& name)
{
    return std::all_of(name.begin(), name.end(), [](char c) {
        return std::isalnum(c) || c == '-' || c == ' ';
    });
}

/// @brief Creates a new mayor object
/// @param employmentStatus The employment status of the mayor, may only be 'unemployed', 'employed' or 'self-employed'
/// @param satisfaction The overall satisfaction the mayor has with the city, may only be between 0-100
/// @param home The structure where the mayor lives
Mayor::Mayor(string employmentStatus, double satisfaction, std::shared_ptr<Structure> home, string name) : Citizen(employmentStatus, satisfaction, home)
{
    if(!isValidName(name) || name == " ")
    {
        this->name = "Mayor " + (++MayorCount);
    }
    else
    {
        this->name = name;
        MayorCount++;
    }
    electedMayor = false;
    voteCount = 0;
    income = new Income(8000, 12000, 5.5, 2.5);
}

/// @brief Returns the name of the mayor, used when voting for a specific mayor
/// @return the name of the mayor
string Mayor::getMayorName()
{
    return name;
}

/// @brief Changes the name of the mayor
/// @param newName the new name of the mayor
void Mayor::setMayorName(string newName)
{
    if(!isValidName(newName))
    {
        return;
    }
    this->name = newName;
}

/// @brief Increases the number of votes the mayor has received
void Mayor::receiveVote()
{
    voteCount++;
}

/// @brief Returns the number of votes a mayor has received from different citizens
/// @return the number of votes a mayor received
int Mayor::getVoteCount()
{
    return voteCount;
}

/// @brief Returns whether the mayor is elected or not
/// @return the status of mayor in terms of the elections
bool Mayor::getElectionStatus()
{
    return electedMayor;
}

/// @brief Changes whether a mayor is elected or not, only changes the status if the passed in parameter differs from current election status
/// @param newStatus the new election status of the mayor
void Mayor::setElectionStatus(bool newStatus)
{
    if(newStatus != electedMayor)
    {
        this->electedMayor = newStatus;
    }
}

/// @brief Static method that returns the number of current active mayors in the city 
/// @return the number of active mayors
int Mayor::getMayorCount()
{
    return MayorCount;
}

/// @brief Returns the income of the mayor
/// @return The income object of the mayor
Income* Mayor::getIncome()
{
    return income;
}

/// @brief Returns a new mayor iterator object which allows a user to iterator through the mayors
/// @return A mayor iterator object
CitizenIterator* Mayor::createCitizenIterator()
{
    vector<Mayor*> mayors = Citizen::getMayors();
    return new MayorIterator(mayors);

}

/// @brief Deletes the mayor object, decreases the number of active mayors
Mayor::~Mayor()
{
    MayorCount--;
    delete income;
}