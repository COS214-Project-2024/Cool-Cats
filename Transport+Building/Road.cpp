#include "Road.h"

Road::Road(string name) {
    this->name = name;

}

Road::~Road() {
    delete this->roadState;
}

void Road::setState(RoadState* state){
    this->roadState = state;
}

RoadState* Road::getState(){
    return this->roadState;
}

bool Road::checkState(){
    return this->roadState->request();
}

string Road::getName(){
    return this->name;
}

