#ifndef CITIZENITERATOR_H
#define CITIIZENITERATOR_H

#include "Citizen.h"

class CitizenIterator{
    public:
        CitizenIterator();
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() const = 0;
        virtual Citizen* currentItem() = 0; 
        virtual ~CitizenIterator();
};
#endif