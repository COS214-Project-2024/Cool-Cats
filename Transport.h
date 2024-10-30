#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>

using namespace std;

class Transport
{
    private:

    public:
        Transport();
        ~Transport();
        virtual void travel() = 0;

};

#endif