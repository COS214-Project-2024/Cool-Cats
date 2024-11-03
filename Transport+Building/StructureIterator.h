#ifndef STRUCTUREITERATOR_H
#define STRUCTUREITERATOR_H

#include <iostream>
#include "Structure.h"

using namespace std;

class StructureIterator
{
    private:

    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() = 0;
        virtual Structure* currentItem() = 0;

};

#endif