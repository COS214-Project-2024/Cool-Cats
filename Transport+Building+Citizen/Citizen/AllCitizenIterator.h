#ifndef ALLCITIZENITERATOR_H
#define ALLCITIZENITERATOR_H

#include "CitizenIterator.h"
#include "Citizen.h"

#include <list>

class AllCitizenIterator : public CitizenIterator{
    public:
        AllCitizenIterator(std::list<Citizen*> citizens);
        void first();
        void next();
        bool isDone() const;
        Citizen* currentItem();
        ~AllCitizenIterator();
};
#endif