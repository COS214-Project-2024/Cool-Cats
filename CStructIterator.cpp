#include "CStructIterator.h"

/// @brief Constructs an iterator for a given vector of structures.
/// @param structures A vector containing pointers to structures to iterate over.
CStructIterator::CStructIterator(const vector<Structure*>& structures) : structures(structures), currentPosition(0) 
{

}

/// @brief Resets the iterator to the first element in the collection.
void CStructIterator::first() 
{
    currentPosition = 0;
}

/// @brief Advances the iterator to the next element in the collection.
void CStructIterator::next() 
{
    if (currentPosition < structures.size()) {
        ++currentPosition;
    }
}

/// @brief Checks if the iterator has reached the end of the collection.
/// @return True if there are no more elements to iterate over; otherwise, false.
bool CStructIterator::isDone() 
{
    return currentPosition >= structures.size();
}

/// @brief Returns the current structure that the iterator points to.
/// @return A pointer to the current Structure if iteration is not complete; otherwise, nullptr.
Structure* CStructIterator::currentItem() 
{
    if (!isDone()) {
        return structures[currentPosition];
    }
    return nullptr; // iterator is done
}
CStructIterator::~CStructIterator()
{
    
}