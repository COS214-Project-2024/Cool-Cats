#ifndef SEWAGEUTILITY_H
#define SEWAGEUTILITY_H

#include "Utilities.h"
#include <string>

class SewageUtility : public Utilities {
public:
    SewageUtility(Structure* s);

    // Handles sewage-related requests; if not handled, passes it down the chain
    void processRequest(const std::string &request) override;

    // Additional sewage-specific methods
    void collectSewage(const std::string &area);
    void treatSewage();
    void monitorSystem();
};

#endif
