#include "UnderConstruction.h"

UnderConstruction::UnderConstruction() {}

UnderConstruction::~UnderConstruction() {}

bool UnderConstruction::request(){
    std::cout << "This road is unusable as it is under-construction, please use another road" << std::endl;
    return false;
}
