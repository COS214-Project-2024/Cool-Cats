#include "CStructIterator.h"

CStructIterator::CStructIterator(const vector<Structure*>& structures) : structures(structures), currentPosition(0) 
{   
    
}

void CStructIterator::first() 
{
    currentPosition = 0;
}

void CStructIterator::next() 
{
    if (currentPosition < structures.size()) {
        ++currentPosition;
    }
}

bool CStructIterator::isDone() 
{
    return currentPosition >= structures.size();
}

Structure* CStructIterator::currentItem() 
{
    if (!isDone()) {
        return structures[currentPosition];
    }
    return nullptr; // iterator is done
}