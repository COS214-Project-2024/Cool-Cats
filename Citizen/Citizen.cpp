#include <iostream>
#include <memory>
#include <cctype>
#include <algorithm>
#include <typeinfo>

#include "Citizen.h"
#include "Mayor.h"
#include "HighCitizen.h"
#include "MiddleCitizen.h"
#include "LowCitizen.h"

using namespace std;

/// @brief Creates a new basic citizen object, with the citizen being unemployed, have a satisfaction of 50 and no home
Citizen::Citizen() 
{ 
    employmentStatus = "Unemployed";
    satisfaction = 50;
    home = nullptr;
}

/// @brief Creates a new citizen object
/// @param employmentStatus The employment status of the citizen, can only be 'unemployed', 'employed', 'self-employed'
/// @param satisfaction The overall satisfaction the citizen has with the city, can only be a value between 0 and 100
/// @param home The structure where the citizen lives
Citizen::Citizen(string employmentStatus, double satisfaction, shared_ptr<Structure> home)
{
    if(!isValidService(employmentStatus))
    {
        this->employmentStatus = " ";
    }
    else if(employmentStatus != "unemployed" && employmentStatus != "employed" && employmentStatus != "self-employed")
    {
        this->employmentStatus = " ";
    }
    else
    {
        this->employmentStatus = employmentStatus;
    }

    if(satisfaction < 0 || satisfaction > 100)
    {
        this->satisfaction = 50;
    }
    else
    {
        this->satisfaction = satisfaction;
    }
    this->home = home;
}

/// @brief Adds a new Citizen to a hierarchy of citizens
/// @param newCitizen The new citizen to be added into the array
void Citizen::addCitizen(unique_ptr<Citizen> newCitizen)
{
    if(newCitizen != nullptr)
    {
        citizens.push_back(std::move(newCitizen));
    }
}

/// @brief Removes a citizen if its in the hierarchy of citizens
/// @param target The citizen to be removed
void Citizen::removeCitizen(Citizen* target)
{
    if(target != nullptr)
    {
        auto it = std::remove_if(citizens.begin(), citizens.end(), [target](const std::unique_ptr<Citizen>& ptr){
            return ptr.get() == target;
        });

        citizens.erase(it, citizens.end());
    }
}
/// @brief Returns the number of citizens registered to the city, includes mayors, high class citizens, middle class citizens and low class citizens 
/// @return The total population of the city
int Citizen::getPopulationCount()
{
    int numMayors = Mayor::getMayorCount();
    int highClass = HighCitizen::getHighClassCitizenCount();
    int middleClass = MiddleCitizen::getMiddleClassCitizenCount();
    int lowClass = LowCitizen::getLowClassCitizenCount();

    return (numMayors+highClass+middleClass+lowClass);
}

/// @brief Adds a new service to the list of services the specific citizen can do
/// @param newService The new service to be added to the list
void Citizen::addService(string newService)
{   
    if(!isValidService(newService))
    {
        return;
    }
    services.push_back(newService);
}   
/// @brief Removes a service, if it exists, from the list of services a specific citizen can do
/// @param oldService the old service that was preexistent in the list
void Citizen::removeService(string oldService)
{
    if(!isValidService(oldService))
    {
        return;
    }

    for(auto s = services.begin(); s != services.end();)
    {
        if(*s == oldService)
        {
            services.erase(s);
            return;
        }
        s++;
    }
}

bool isValidService(const string& service)
{
    return std::all_of(service.begin(), service.end(), [](char c) {
        return std::isalnum(c) || c == '-' || c == ' ';
    });
}

/// @brief Moves where the citizen lives to a different structure, Creates a deep copy of the new home
/// @param newHome The new Structure where the citizen will live
void Citizen::moveHomes(shared_ptr<Structure> newHome)
{
    if(newHome != nullptr)
    {
        home = std::make_shared<Structure>(*newHome);
    }
}

/// @brief Returns the current satisfaction of the citizen with the city overall, factors that influence satisfaction include tax, policies and budge allocation set by the government 
/// @return the satisfaction of the citizen
double Citizen::getSatisfaction()
{
    return satisfaction;
}

/// @brief Changes the satisfaction of the citizen, to a new satisfaction number. Satisfaction can only be a number between 0 and 100
/// @param satisfaction the new satisfaction number of the citizen
void Citizen::setSatisfaction(double satisfaction)
{
    if(satisfaction < 0 || satisfaction > 100)
    {
        return;
    }
    this->satisfaction = satisfaction;
}

/// @brief Returns the current employment status of the citizen
/// @return the employment status, can be either 'unemployed', 'employed' or 'self-employed'
string Citizen::getEmploymentStatus()
{
    return employmentStatus;
}

/// @brief Changes the employment status of the citizen to a new employment status 
/// @param employment the new employment status, can only be either 'unemployed', 'employed' or 'self-employed'
void Citizen::setEmploymentStatus(string employment)
{
    if(!isValidService(employment))
    {
        return;
    }

    if(employment != "unemployed" || employment != "employed" || employment != "self-employed")
    {
        return;
    }
    this->employmentStatus = employment;
}
void Citizen::determineMayor()
{
    int maxVote = 0;
    Mayor* candidate = nullptr;
    Mayor *currMayor = nullptr;

    for(auto m = citizens.begin(); m != citizens.end(); m++)
    {
        Mayor* c =  dynamic_cast<Mayor*>(m->get());

        if(c && c->getVoteCount() > maxVote)
        {
            maxVote = c->getVoteCount();
            candidate = c;
        }
        else if(c && c->getElectionStatus())
        {
            currMayor = c;
        }
    }

    if(candidate != nullptr)
    {
        candidate->setElectionStatus(true);
    }
    
    if(currMayor != nullptr)
    {
        currMayor->setElectionStatus(false);
    }
}

/// @brief Helper method for derived classes, used to get all active mayors of the city
/// @return vector of all active mayors
vector<Mayor*> Citizen::getMayors()
{
    vector<Mayor*> mayors;
    for(auto c = citizens.begin(); c != citizens.end(); c++)
    {
        Mayor *m = dynamic_cast<Mayor*>(c->get());

        if(m)
        {
            mayors.push_back(m);
        }
    }
    return mayors;
}

//TO-DO 
//Thabiso needs to implement the memento functions into citizen
// PopulationMemento* Citizen::createMemento()
// {

// }
// void Citizen::setMemento(PopulationMemento* memento)
// {

// }

