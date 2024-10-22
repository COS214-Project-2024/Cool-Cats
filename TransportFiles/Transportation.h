#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <iostream>
#include "Transport.h"

using namespace std;

class Transportation
{
    private:
        Transport* transport;
    public:
        Transportation(Transport* transport);
        ~Transportation();
        void travel();
        //virtual void update() = 0;

};

#endif