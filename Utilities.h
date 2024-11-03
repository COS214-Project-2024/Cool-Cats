#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include "BasicStructure.h"
using namespace std;

class Utilities {
public:
    Utilities(BasicStructure* s);
    // /virtual ~Utilities() = default;

    // Set the next handler in the chain
    void setNext(Utilities* nextHandler);

    // The method to handle requests in the chain
    virtual void processRequest(const std::string &request);
    

protected:
    Utilities* next; // Pointer to the next handler in the chain
    BasicStructure* struc;
};

#endif
