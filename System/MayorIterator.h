#ifndef MAYORITERATOR_H
#define MAYORITERATOR_H

#include "Mayor.h"
#include "CitizenIterator.h"

#include <vector>

class MayorIterator : public CitizenIterator{
    public:
        MayorIterator(std::vector<Mayor*> mayors);
        void first();
        void next();
        bool isDone() const;
        Mayor* currentItem();
        ~MayorIterator();

    private:
        std::vector<Mayor*> mayors;
        Mayor* current;
        size_t index;
};
#endif