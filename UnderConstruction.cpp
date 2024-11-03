#include "UnderConstruction.h"

/// @brief Constructs an UnderConstruction object representing a road state where the road is under construction.
UnderConstruction::UnderConstruction() {}

/// @brief Destructor for the UnderConstruction object.
UnderConstruction::~UnderConstruction() {}

/// @brief Processes a request to use the road, indicating that it is unusable due to construction.
/// @return False, indicating the road cannot be used.
bool UnderConstruction::request(){
    std::cout << "This road is unusable as it is under construction, please use another road" << std::endl;
    return false;
}
