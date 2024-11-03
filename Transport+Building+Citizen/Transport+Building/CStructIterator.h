#ifndef CSTRUCTITERATOR_H
#define CSTRUCTITERATOR_H

#include <iostream>
#include "StructureIterator.h"
#include "Structure.h"
#include <vector>

using namespace std;

class CStructIterator : public StructureIterator
{
    private:
        vector<Structure*> structures;
        int currentPosition;
    public:
        CStructIterator(const vector<Structure*>& structures);
        void first();
        void next();
        bool isDone();
        Structure* currentItem();

};

#endif