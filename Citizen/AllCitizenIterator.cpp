#include <iostream>
#include <algorithm>
#include <vector>

#include "AllCitizenIterator.h"

using namespace std;

/// @brief Creates a new AllCitizen Iterator object that allows iteration through a list of citizens
/// @param citizens The vector of all current citizens in the city
AllCitizenIterator::AllCitizenIterator(vector<Citizen*>& citizens) : citizens(citizens)
{
    if(!citizens.empty())
    {
        current = citizens[0];
    }
    else
    {
        current = nullptr;
    }
    index = 0;
}

/// @brief Makes the iterator start at the first citizen
void AllCitizenIterator::first()
{
    if(!citizens.empty())
    {
        current = citizens[0];
        return;
    }
    current = nullptr;
}

/// @brief Moves the iterator to the next citizen
void AllCitizenIterator::next()
{
    if(current != nullptr && !citizens.empty())
    {
        if(index+1 < citizens.size())
        {
            current = citizens[++index];
        }
        else
        {
            current = nullptr;
        }
    }
}

/// @brief Checks and returns whether the iterator is past the last citizen in the vector
/// @return Whether or not the iterator is past the last element
bool AllCitizenIterator::isDone() const
{
    if(current == nullptr)
    {
        return true;
    }
    return false;
}


/// @brief Returns the current citizen in the vector of citizens
/// @return Returns the position of the iterator in the citizens vector
Citizen* AllCitizenIterator::currentItem()
{
    return current;
}

AllCitizenIterator::~AllCitizenIterator()
{
    current = nullptr;
}