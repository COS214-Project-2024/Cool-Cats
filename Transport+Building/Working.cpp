#include "Working.h"

/// @brief Constructs a Working object representing a road state where the road is usable.
/// This state indicates that the road can be traveled on.
Working::Working() {}

/// @brief Destructor for the Working object.
Working::~Working() {}

/// @brief Processes a request to use the road, indicating that it is usable for travel.
/// @return True, indicating the road can be used.
bool Working::request(){
    std::cout << "This road is usable to travel on" << std::endl;
    return true;
}
