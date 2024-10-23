#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include <iostream>
#include "RoadState.h"

using namespace std;

class UnderConstruction : public RoadState
{
    private:

    public:
        UnderConstruction();
        ~UnderConstruction();
        bool request();

};

#endif