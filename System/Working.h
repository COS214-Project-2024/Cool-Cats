#ifndef WORKING_H
#define WORKING_H

#include <iostream>
#include "RoadState.h"

using namespace std;

class Working : public RoadState
{
    private:

    public:
        Working();
        ~Working();
        bool request();

};

#endif