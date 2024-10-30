#include <iostream>

#include "MayorIterator.h"

using namespace std;

/// @brief Creates a new Mayor Iterator object that allows iteration through a list of mayors
/// @param mayors The vector of current mayors in the city
MayorIterator::MayorIterator(vector<Mayor*> mayors)
{
    if(mayors.size() != 0)
    {
        this->mayors = mayors;
        this->current = mayors[0];
    }
}
/// @brief Makes the iterator start at the first mayor
void MayorIterator::first()
{
    if(!mayors.empty())
    {
        current = mayors[0];
        return;
    }
    current = nullptr;
}
/// @brief Moves the iterator to the next mayor
void MayorIterator::next()
{
    if(current != nullptr)
    {
        auto it = find(mayors.begin(), mayors.end(), current);
        if(it != mayors.end() && ++it != mayors.end())
        {
            current = *it;
        }
        else
        {
            current = nullptr;
        }
    }
}

/// @brief Checks and returns whether the iterator is past the last mayor in the vector
/// @return Whether or not the iterator is past the last element
bool MayorIterator::isDone() const{
    if(current == nullptr)
    {
        return true;
    }
    return false;
}

/// @brief Returns the current mayor in the vector of mayors 
/// @return Returns the position of the iterator in the mayors vector
Mayor* MayorIterator::currentItem()
{
    return current;
}

MayorIterator::~MayorIterator()
{
    current = nullptr;
}