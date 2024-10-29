#ifndef ALLCITIZENITERATOR_H
#define ALLCITIZENITERATOR_H

#include "CitizenIterator.h"
#include "Citizen.h"

#include <vector>
#include <memory>

class AllCitizenIterator : public CitizenIterator{
    public:
        AllCitizenIterator(std::vector<std::unique_ptr<Citizen>>& citizens);
        void first();
        void next();
        bool isDone() const;
        Citizen* currentItem();
        ~AllCitizenIterator();

    private:
        std::vector<std::unique_ptr<Citizen>> citizens;
        Citizen* current;
};
#endif