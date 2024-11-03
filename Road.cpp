#include "Road.h"

/// @brief Constructs a Road object with a specified name.
/// @param name The name of the road.
Road::Road(string name) {
    this->name = name;
}

/// @brief Destructor for the Road object. Frees the associated RoadState object.
Road::~Road() {
    delete this->roadState;
}

/// @brief Sets the state of the road.
/// @param state A pointer to a RoadState object representing the road's current state.
void Road::setState(RoadState* state){
    this->roadState = state;
}

/// @brief Retrieves the current state of the road.
/// @return A pointer to the RoadState object representing the road's current state.
RoadState* Road::getState(){
    return this->roadState;
}

/// @brief Checks if the road's current state allows passage.
/// @return True if the road's state allows passage, otherwise false.
bool Road::checkState(){
    return this->roadState->request();
}

/// @brief Retrieves the name of the road.
/// @return The name of the road as a string.
string Road::getName(){
    return this->name;
}
