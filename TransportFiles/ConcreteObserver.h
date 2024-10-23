#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H

#include <iostream>
#include "Transportation.h"
#include "Road.h"

using namespace std;

class ConcreteObserver : public Transportation
{
    private:
        Road* subject;
        Transport* transport;
        bool status;
    public:
        ConcreteObserver(Road* subject, Transport* transport);
        ~ConcreteObserver();
        void update();
        void travel();

};

#endif