#ifndef WASTEUTILITY_H
#define WASTEUTILITY_H

#include "Utilities.h"
#include <string>

class WasteUtility : public Utilities {
public:
    WasteUtility(BasicStructure* s) ;

    // Handles waste-related requests; if not handled, passes it down the chain
    void processRequest(const std::string &request) override;

    // Additional waste-specific methods
    void collectWaste();
    void separateWaste();
    void conductCheck();
};

#endif
