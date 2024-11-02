#ifndef MAYORITERATOR_H
#define MAYORITERATOR_H

#include "Citizen.h"
#include "CitizenIterator.h"

#include <list>

class MayorIterator : public CitizenIterator{
    public:
        MayorIterator(std::list<Citizen*> citizens);
        void first();
        void next();
        bool isDone() const;
        Citizen* currentItem();
        ~MayorIterator();
};
#endif