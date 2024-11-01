#ifndef ALLCITIZENITERATOR_H
#define ALLCITIZENITERATOR_H

#include "CitizenIterator.h"
#include "Citizen.h"

#include <vector>
#include <memory>

class AllCitizenIterator : public CitizenIterator{
    public:
        AllCitizenIterator(std::vector<Citizen*>& citizens);
        void first();
        void next();
        bool isDone() const;
        Citizen* currentItem();
        ~AllCitizenIterator();

    private:
        std::vector<Citizen*>& citizens;
        Citizen* current;
        int index;
};
#endif