#ifndef POWERUTILITY_H
#define POWERUTILITY_H

#include "Utilities.h"
#include "Energy.h"
#include <string>

class PowerUtility : public Utilities {
private:
    Energy* energy; // Represents the energy resource // Legacy system reference
    double powerMega; // power in circulation
public:
    PowerUtility(Structure* s);

    // Handles power-related requests; if not handled, passes it down the chain
    void processRequest(const std::string &request) override;

    // Additional power-specific methods
    void generatePower();
};

#endif
